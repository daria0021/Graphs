#include "generators/FixedBridgesGenerator.hpp"
#include <vector>
#include <stdexcept>

FixedBridgesGenerator::FixedBridgesGenerator(int n, int bridges) : n_(n), bridges_(bridges) {
    if (bridges_ > n_ - 1) throw std::invalid_argument("too many bridges");
}

std::unique_ptr<Graph> FixedBridgesGenerator::generate() {
    auto g = std::make_unique<Graph>(false);
    for (int i = 0; i < n_; ++i) g->addVertex(i);

    std::vector<int> compSizes(bridges_ + 1, 1);
    int remaining = n_ - (bridges_ + 1);
    for (int i = 0; i < remaining; ++i) {
        compSizes[i % (bridges_ + 1)]++;
    }

    int start = 0;
    for (int i = 0; i <= bridges_; ++i) {
        int size = compSizes[i];
        for (int j = start; j < start + size - 1; ++j) {
            g->addEdge(j, j + 1);
        }
        if (i < bridges_) {
            g->addEdge(start + size - 1, start + size);
        }
        start += size;
    }
    return g;
}