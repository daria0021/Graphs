#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include "Graph.hpp"
#include <memory>

class Generator {
public:
    virtual ~Generator() = default;
    virtual std::unique_ptr<Graph> generate() = 0;
};

#endif