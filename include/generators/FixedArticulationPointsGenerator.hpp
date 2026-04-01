#ifndef FIXEDARTICULATIONPOINTSGENERATOR_HPP
#define FIXEDARTICULATIONPOINTSGENERATOR_HPP

#include "Generator.hpp"

class FixedArticulationPointsGenerator : public Generator {
public:
    FixedArticulationPointsGenerator(int n, int ap);
    std::unique_ptr<Graph> generate() override;
private:
    int n_, ap_;
};

#endif