#include "algorithms/DFSVisitor.hpp"
#include <stack>
#include <utility>

void depthFirstSearch(const Graph& g, Graph::Vertex start,
                      DFSVisitor& visitor,
                      std::unordered_set<Graph::Vertex>& visited) {
    std::stack<std::pair<Graph::Vertex, std::vector<Graph::Vertex>::const_iterator>> st;
    visited.insert(start);
    visitor.discoverVertex(start);
    st.push({start, g.neighbors(start).begin()});
    while (!st.empty()) {
        auto& [v, it] = st.top();
        if (it != g.neighbors(v).end()) {
            Graph::Vertex w = *it;
            ++it;
            if (!visited.count(w)) {
                visited.insert(w);
                visitor.discoverVertex(w);
                visitor.treeEdge(v, w);
                st.push({w, g.neighbors(w).begin()});
            } else {
                visitor.backEdge(v, w);
            }
        } else {
            st.pop();
            visitor.finishVertex(v);
        }
    }
}