#ifndef RANDOMGRAPHGENERATOR_HPP
#define RANDOMGRAPHGENERATOR_HPP

#include "Generator.hpp"

class RandomGraphGenerator : public Generator {
public:
    RandomGraphGenerator(int n, double p);
    std::unique_ptr<Graph> generate() override;
private:
    int n_;
    double p_;
};

#endif