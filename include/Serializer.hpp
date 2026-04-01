#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Graph.hpp"
#include <string>

class Serializer {
public:
    virtual ~Serializer() = default;
    virtual void serialize(const Graph& graph, const std::string& filename) = 0;
};

#endif