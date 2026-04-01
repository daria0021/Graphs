#include "serializers/Program4YouSerializer.hpp"
#include <fstream>

void Program4YouSerializer::serialize(const Graph& graph, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) throw std::runtime_error("Cannot open file");
    for (auto [u, v] : graph.edges()) {
        out << u << " " << v << "\n";
    }
}