#ifndef METRICS_HPP
#define METRICS_HPP

#include "Graph.hpp"

class Metrics {
public:
    static double density(const Graph& g);
    static int diameter(const Graph& g);
    static double transitivity(const Graph& g);
    static int connectedComponents(const Graph& g);
    static int articulationPoints(const Graph& g);
    static int bridges(const Graph& g);
    static bool isBipartite(const Graph& g);
    static int greedyChromaticNumber(const Graph& g);
};

#endif