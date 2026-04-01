#include "generators/TreeGenerator.hpp"

TreeGenerator::TreeGenerator(int n) : n_(n) {}

std::unique_ptr<Graph> TreeGenerator::generate() {
    auto g = std::make_unique<Graph>(false);
    for (int i = 0; i < n_; ++i) g->addVertex(i);
    for (int i = 0; i < n_-1; ++i) g->addEdge(i, i+1);
    return g;
}