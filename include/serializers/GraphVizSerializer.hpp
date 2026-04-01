#ifndef GRAPHVIZSERIALIZER_HPP
#define GRAPHVIZSERIALIZER_HPP

#include "Serializer.hpp"

class GraphVizSerializer : public Serializer {
public:
    GraphVizSerializer(bool showSpanningTree = false,
                       bool showRandomCycle = false,
                       bool showEdgeBiconnected = false);
    void serialize(const Graph& graph, const std::string& filename) override;
private:
    bool showSpanningTree_;
    bool showRandomCycle_;
    bool showEdgeBiconnected_;
};

#endif