#include "generators/RandomGraphGenerator.hpp"
#include <random>

RandomGraphGenerator::RandomGraphGenerator(int n, double p) : n_(n), p_(p) {}

std::unique_ptr<Graph> RandomGraphGenerator::generate() {
    auto g = std::make_unique<Graph>(false);
    for (int i = 0; i < n_; ++i) g->addVertex(i);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < n_; ++i) {
        for (int j = i+1; j < n_; ++j) {
            if (dis(gen) < p_) {
                g->addEdge(i, j);
            }
        }
    }
    return g;
}