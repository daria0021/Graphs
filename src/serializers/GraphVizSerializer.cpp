#include "serializers/GraphVizSerializer.hpp"
#include "algorithms/BiconnectedComponents.hpp"
#include <fstream>

GraphVizSerializer::GraphVizSerializer(bool showSpanningTree, bool showRandomCycle, bool showEdgeBiconnected)
    : showSpanningTree_(showSpanningTree), showRandomCycle_(showRandomCycle), showEdgeBiconnected_(showEdgeBiconnected) {}

void GraphVizSerializer::serialize(const Graph& graph, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) throw std::runtime_error("Cannot open file");
    out << (graph.isDirected() ? "digraph G {\n" : "graph G {\n");
    out << "  node [shape=circle];\n";

    for (auto v : graph.vertices()) {
        out << "  " << v << ";\n";
    }

    for (auto [u, v] : graph.edges()) {
        out << "  " << u << (graph.isDirected() ? " -> " : " -- ") << v << ";\n";
    }

    out << "}\n";
}