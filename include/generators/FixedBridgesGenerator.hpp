#ifndef FIXEDBRIDGESGENERATOR_HPP
#define FIXEDBRIDGESGENERATOR_HPP

#include "Generator.hpp"

class FixedBridgesGenerator : public Generator {
public:
    FixedBridgesGenerator(int n, int bridges);
    std::unique_ptr<Graph> generate() override;
private:
    int n_, bridges_;
};

#endif