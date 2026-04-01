#ifndef FIXEDCOMPONENTSGENERATOR_HPP
#define FIXEDCOMPONENTSGENERATOR_HPP

#include "Generator.hpp"

class FixedComponentsGenerator : public Generator {
public:
    FixedComponentsGenerator(int n, int comp);
    std::unique_ptr<Graph> generate() override;
private:
    int n_, comp_;
};

#endif