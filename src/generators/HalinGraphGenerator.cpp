#include "generators/HalinGraphGenerator.hpp"
#include <stdexcept>

HalinGraphGenerator::HalinGraphGenerator(int n) : n_(n) {}

std::unique_ptr<Graph> HalinGraphGenerator::generate() {
    auto g = std::make_unique<Graph>(false);
    if (n_ == 4) {
        for (int i = 0; i < 4; ++i) g->addVertex(i);
        g->addEdge(0,1); g->addEdge(0,2); g->addEdge(0,3);
        g->addEdge(1,2); g->addEdge(2,3); g->addEdge(3,1);
    } else {
        throw std::runtime_error("Halin graph generation for n != 4 not implemented");
    }
    return g;
}