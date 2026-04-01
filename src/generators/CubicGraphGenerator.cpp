#include "generators/CubicGraphGenerator.hpp"
#include <stdexcept>

CubicGraphGenerator::CubicGraphGenerator(int n) : n_(n) {
    if (n < 4 || n % 2 != 0) throw std::invalid_argument("n must be even and >= 4");
}

std::unique_ptr<Graph> CubicGraphGenerator::generate() {
    auto g = std::make_unique<Graph>(false);
    for (int i = 0; i < n_; ++i) g->addVertex(i);
    for (int i = 0; i < n_-1; ++i) g->addEdge(i, i+1);
    g->addEdge(n_-1, 0);
    for (int i = 0; i < n_/2; ++i) {
        g->addEdge(i, i + n_/2);
    }
    return g;
}