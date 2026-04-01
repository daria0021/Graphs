#ifndef DFS_VISITOR_HPP
#define DFS_VISITOR_HPP

#include "Graph.hpp"
#include <unordered_set>
#include <functional>

class DFSVisitor {
public:
    virtual ~DFSVisitor() = default;
    virtual void discoverVertex(Graph::Vertex v) {}
    virtual void finishVertex(Graph::Vertex v) {}
    virtual void treeEdge(Graph::Vertex u, Graph::Vertex v) {}
    virtual void backEdge(Graph::Vertex u, Graph::Vertex v) {}
    virtual void forwardOrCrossEdge(Graph::Vertex u, Graph::Vertex v) {}
};

void depthFirstSearch(const Graph& g, Graph::Vertex start,
                      DFSVisitor& visitor,
                      std::unordered_set<Graph::Vertex>& visited);

#endif