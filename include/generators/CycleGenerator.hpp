#ifndef CYCLEGENERATOR_HPP
#define CYCLEGENERATOR_HPP

#include "Generator.hpp"

class CycleGenerator : public Generator {
public:
    CycleGenerator(int n);
    std::unique_ptr<Graph> generate() override;
private:
    int n_;
};

#endif