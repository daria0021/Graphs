#include "parsers/SNAPParser.hpp"
#include <fstream>
#include <sstream>

std::unique_ptr<Graph> SNAPParser::parse(const std::string& filename) {
    auto g = std::make_unique<Graph>(false);
    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Cannot open file");
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        std::istringstream iss(line);
        Graph::Vertex u, v;
        if (iss >> u >> v) {
            g->addEdge(u, v);
        }
    }
    return g;
}