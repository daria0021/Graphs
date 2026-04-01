#include "generators/FixedArticulationPointsGenerator.hpp"
#include <stdexcept>

FixedArticulationPointsGenerator::FixedArticulationPointsGenerator(int n, int ap) : n_(n), ap_(ap) {}

std::unique_ptr<Graph> FixedArticulationPointsGenerator::generate() {
    auto g = std::make_unique<Graph>(false);
    for (int i = 0; i < n_; ++i) g->addVertex(i);
    if (ap_ > 0) {
        for (int i = 0; i < ap_-1; ++i) {
            g->addEdge(i, i+1);
        }
        int next = ap_;
        for (int i = 0; i < ap_; ++i) {
            if (next < n_) {
                g->addEdge(i, next++);
            }
        }
        while (next < n_) {
            g->addEdge(0, next++);
        }
    } else {
        for (int i = 0; i < n_-1; ++i) g->addEdge(i, i+1);
        if (n_ > 2) g->addEdge(n_-1, 0);
    }
    return g;
}