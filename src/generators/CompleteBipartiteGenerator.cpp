#include "generators/CompleteBipartiteGenerator.hpp"

CompleteBipartiteGenerator::CompleteBipartiteGenerator(int n, int m) : n_(n), m_(m) {}

std::unique_ptr<Graph> CompleteBipartiteGenerator::generate() {
    auto g = std::make_unique<Graph>(false);
    for (int i = 0; i < n_ + m_; ++i) g->addVertex(i);
    for (int i = 0; i < n_; ++i) {
        for (int j = n_; j < n_ + m_; ++j) {
            g->addEdge(i, j);
        }
    }
    return g;
}