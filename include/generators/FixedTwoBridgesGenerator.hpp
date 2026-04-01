#ifndef FIXEDTWOBRIDGESGENERATOR_HPP
#define FIXEDTWOBRIDGESGENERATOR_HPP

#include "Generator.hpp"

class FixedTwoBridgesGenerator : public Generator {
public:
    FixedTwoBridgesGenerator(int n, int twoBridges);
    std::unique_ptr<Graph> generate() override;
private:
    int n_, twoBridges_;
};

#endif