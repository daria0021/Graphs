#include "generators/CompleteGraphGenerator.hpp"

CompleteGraphGenerator::CompleteGraphGenerator(int n) : n_(n) {}

std::unique_ptr<Graph> CompleteGraphGenerator::generate() {
    auto g = std::make_unique<Graph>(false);
    for (int i = 0; i < n_; ++i) g->addVertex(i);
    for (int i = 0; i < n_; ++i) {
        for (int j = i+1; j < n_; ++j) {
            g->addEdge(i, j);
        }
    }
    return g;
}