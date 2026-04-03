#ifndef BICONNECTED_COMPONENTS_HPP
#define BICONNECTED_COMPONENTS_HPP

#include "Graph.hpp"
#include <vector>
#include <unordered_set>

std::vector<std::vector<Graph::Edge>> edgeBiconnectedComponents(const Graph& g);
std::vector<std::unordered_set<Graph::Vertex>> vertexBiconnectedComponents(const Graph& g);

#endif
