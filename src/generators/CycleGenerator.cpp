#include "generators/CycleGenerator.hpp"

CycleGenerator::CycleGenerator(int n) : n_(n) {}

std::unique_ptr<Graph> CycleGenerator::generate() {
    auto g = std::make_unique<Graph>(false);
    for (int i = 0; i < n_; ++i) g->addVertex(i);
    for (int i = 0; i < n_-1; ++i) g->addEdge(i, i+1);
    if (n_ > 2) g->addEdge(n_-1, 0);
    return g;
}