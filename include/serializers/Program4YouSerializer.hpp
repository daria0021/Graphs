#ifndef PROGRAM4YOUSERIALIZER_HPP
#define PROGRAM4YOUSERIALIZER_HPP

#include "Serializer.hpp"

class Program4YouSerializer : public Serializer {
public:
    void serialize(const Graph& graph, const std::string& filename) override;
};

#endif