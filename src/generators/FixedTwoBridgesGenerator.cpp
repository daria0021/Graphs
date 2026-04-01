#include "generators/FixedTwoBridgesGenerator.hpp"
#include <stdexcept>

FixedTwoBridgesGenerator::FixedTwoBridgesGenerator(int n, int twoBridges) : n_(n), twoBridges_(twoBridges) {}

std::unique_ptr<Graph> FixedTwoBridgesGenerator::generate() {
    auto g = std::make_unique<Graph>(false);
    for (int i = 0; i < n_; ++i) g->addVertex(i);
    // Заглушка
    return g;
}