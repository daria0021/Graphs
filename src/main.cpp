#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

#include "Graph.hpp"
#include "Parser.hpp"
#include "Serializer.hpp"
#include "Generator.hpp"
#include "Metrics.hpp"

#include "parsers/EdgeListParser.hpp"
#include "parsers/AdjacencyMatrixParser.hpp"
#include "parsers/DIMACSParser.hpp"
#include "parsers/SNAPParser.hpp"

#include "generators/CompleteGraphGenerator.hpp"
#include "generators/CompleteBipartiteGenerator.hpp"
#include "generators/TreeGenerator.hpp"
#include "generators/StarGenerator.hpp"
#include "generators/CycleGenerator.hpp"
#include "generators/PathGenerator.hpp"
#include "generators/WheelGenerator.hpp"
#include "generators/RandomGraphGenerator.hpp"
#include "generators/CubicGraphGenerator.hpp"
#include "generators/FixedComponentsGenerator.hpp"
#include "generators/FixedBridgesGenerator.hpp"
#include "generators/FixedArticulationPointsGenerator.hpp"
#include "generators/FixedTwoBridgesGenerator.hpp"
#include "generators/HalinGraphGenerator.hpp"

#include "serializers/GraphVizSerializer.hpp"
#include "serializers/Program4YouSerializer.hpp"

std::unique_ptr<Parser> createParser(const std::string& format) {
    if (format == "edgelist") return std::make_unique<EdgeListParser>();
    if (format == "adjmatrix") return std::make_unique<AdjacencyMatrixParser>();
    if (format == "dimacs") return std::make_unique<DIMACSParser>();
    if (format == "snap") return std::make_unique<SNAPParser>();
    throw std::runtime_error("Unknown parser format");
}

std::unique_ptr<Generator> createGenerator(const std::string& type, const std::vector<int>& params) {
    if (type == "complete") {
        if (params.size() < 1) throw std::runtime_error("Need n");
        return std::make_unique<CompleteGraphGenerator>(params[0]);
    }
    if (type == "complete_bipartite") {
        if (params.size() < 2) throw std::runtime_error("Need n,m");
        return std::make_unique<CompleteBipartiteGenerator>(params[0], params[1]);
    }
    if (type == "tree") {
        if (params.size() < 1) throw std::runtime_error("Need n");
        return std::make_unique<TreeGenerator>(params[0]);
    }
    if (type == "star") {
        if (params.size() < 1) throw std::runtime_error("Need n");
        return std::make_unique<StarGenerator>(params[0]);
    }
    if (type == "cycle") {
        if (params.size() < 1) throw std::runtime_error("Need n");
        return std::make_unique<CycleGenerator>(params[0]);
    }
    if (type == "path") {
        if (params.size() < 1) throw std::runtime_error("Need n");
        return std::make_unique<PathGenerator>(params[0]);
    }
    if (type == "wheel") {
        if (params.size() < 1) throw std::runtime_error("Need n");
        return std::make_unique<WheelGenerator>(params[0]);
    }
    if (type == "random") {
        if (params.size() < 2) throw std::runtime_error("Need n, p (in percents)");
        return std::make_unique<RandomGraphGenerator>(params[0], params[1] / 100.0);
    }
    if (type == "cubic") {
        if (params.size() < 1) throw std::runtime_error("Need n");
        return std::make_unique<CubicGraphGenerator>(params[0]);
    }
    if (type == "components") {
        if (params.size() < 2) throw std::runtime_error("Need n, comp");
        return std::make_unique<FixedComponentsGenerator>(params[0], params[1]);
    }
    if (type == "bridges") {
        if (params.size() < 2) throw std::runtime_error("Need n, bridges");
        return std::make_unique<FixedBridgesGenerator>(params[0], params[1]);
    }
    if (type == "articulation") {
        if (params.size() < 2) throw std::runtime_error("Need n, ap");
        return std::make_unique<FixedArticulationPointsGenerator>(params[0], params[1]);
    }
    if (type == "two_bridges") {
        if (params.size() < 2) throw std::runtime_error("Need n, twoBridges");
        return std::make_unique<FixedTwoBridgesGenerator>(params[0], params[1]);
    }
    if (type == "halin") {
        if (params.size() < 1) throw std::runtime_error("Need n");
        return std::make_unique<HalinGraphGenerator>(params[0]);
    }
    throw std::runtime_error("Unknown generator type");
}

void printHelp() {
    std::cout << "Commands:\n";
    std::cout << "  load <filename> <format>   - load graph from file (formats: edgelist, adjmatrix, dimacs, snap)\n";
    std::cout << "  generate <type> [params]   - generate graph (types: complete, complete_bipartite, tree, star, cycle, path, wheel, random, cubic, components, bridges, articulation, two_bridges, halin)\n";
    std::cout << "  save <filename> <format>   - save graph (formats: dot, edges)\n";
    std::cout << "  metric <name>              - compute metric (density, diameter, transitivity, components, articulation, bridges, bipartite, chromatic)\n";
    std::cout << "  quit                       - exit\n";
}

int main() {
    std::cout << "GraphoDro4 Console\n";
    std::unique_ptr<Graph> graph;
    std::string line;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);
        if (line == "quit") break;
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;
        if (cmd == "load") {
            std::string filename, format;
            iss >> filename >> format;
            try {
                auto parser = createParser(format);
                graph = parser->parse(filename);
                std::cout << "Graph loaded from " << filename << "\n";
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
            }
        } else if (cmd == "generate") {
            std::string type;
            iss >> type;
            std::vector<int> params;
            int p;
            while (iss >> p) params.push_back(p);
            try {
                auto gen = createGenerator(type, params);
                graph = gen->generate();
                std::cout << "Graph generated: " << type << "\n";
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
            }
        } else if (cmd == "save") {
            if (!graph) { std::cout << "No graph loaded.\n"; continue; }
            std::string filename, format;
            iss >> filename >> format;
            std::unique_ptr<Serializer> ser;
            if (format == "dot") {
                ser = std::make_unique<GraphVizSerializer>();
            } else if (format == "edges") {
                ser = std::make_unique<Program4YouSerializer>();
            } else {
                std::cout << "Unknown format.\n";
                continue;
            }
            try {
                ser->serialize(*graph, filename);
                std::cout << "Graph saved to " << filename << "\n";
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
            }
        } else if (cmd == "metric") {
            if (!graph) { std::cout << "No graph loaded.\n"; continue; }
            std::string metric;
            iss >> metric;
            if (metric == "density") {
                std::cout << "Density: " << Metrics::density(*graph) << "\n";
            } else if (metric == "diameter") {
                std::cout << "Diameter: " << Metrics::diameter(*graph) << "\n";
            } else if (metric == "transitivity") {
                std::cout << "Transitivity: " << Metrics::transitivity(*graph) << "\n";
            } else if (metric == "components") {
                std::cout << "Connected components: " << Metrics::connectedComponents(*graph) << "\n";
            } else if (metric == "articulation") {
                std::cout << "Articulation points: " << Metrics::articulationPoints(*graph) << "\n";
            } else if (metric == "bridges") {
                std::cout << "Bridges: " << Metrics::bridges(*graph) << "\n";
            } else if (metric == "bipartite") {
                std::cout << "Is bipartite: " << (Metrics::isBipartite(*graph) ? "yes" : "no") << "\n";
            } else if (metric == "chromatic") {
                std::cout << "Greedy chromatic number: " << Metrics::greedyChromaticNumber(*graph) << "\n";
            } else {
                std::cout << "Unknown metric.\n";
            }
        } else if (cmd == "help") {
            printHelp();
        } else {
            std::cout << "Unknown command. Type 'help'.\n";
        }
    }
    return 0;
}