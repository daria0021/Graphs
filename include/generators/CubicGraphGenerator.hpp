#ifndef CUBICGRAPHGENERATOR_HPP
#define CUBICGRAPHGENERATOR_HPP

#include "Generator.hpp"

class CubicGraphGenerator : public Generator {
public:
    CubicGraphGenerator(int n);
    std::unique_ptr<Graph> generate() override;
private:
    int n_;
};

#endif