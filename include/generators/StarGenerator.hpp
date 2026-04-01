#ifndef STARGENERATOR_HPP
#define STARGENERATOR_HPP

#include "Generator.hpp"

class StarGenerator : public Generator {
public:
    StarGenerator(int n);
    std::unique_ptr<Graph> generate() override;
private:
    int n_;
};

#endif