#ifndef PATHGENERATOR_HPP
#define PATHGENERATOR_HPP

#include "Generator.hpp"

class PathGenerator : public Generator {
public:
    PathGenerator(int n);
    std::unique_ptr<Graph> generate() override;
private:
    int n_;
};

#endif