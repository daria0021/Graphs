#include "generators/WheelGenerator.hpp"

WheelGenerator::WheelGenerator(int n) : n_(n) {}

std::unique_ptr<Graph> WheelGenerator::generate() {
    auto g = std::make_unique<Graph>(false);
    for (int i = 0; i < n_; ++i) g->addVertex(i);
    for (int i = 1; i < n_-1; ++i) g->addEdge(i, i+1);
    if (n_ > 3) g->addEdge(n_-1, 1);
    for (int i = 1; i < n_; ++i) g->addEdge(0, i);
    return g;
}