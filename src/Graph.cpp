#include "Graph.hpp"

Graph::Graph(bool directed) : directed_(directed) {}

void Graph::addVertex(Vertex v) {
    adj_.try_emplace(v, std::unordered_map<Vertex, double>());
}

void Graph::removeVertex(Vertex v) {
    adj_.erase(v);
    for (auto& [_, neigh] : adj_) {
        neigh.erase(v);
    }
}

bool Graph::hasVertex(Vertex v) const {
    return adj_.find(v) != adj_.end();
}

size_t Graph::vertexCount() const {
    return adj_.size();
}

std::vector<Graph::Vertex> Graph::vertices() const {
    std::vector<Vertex> res;
    res.reserve(adj_.size());
    for (const auto& [v, _] : adj_) res.push_back(v);
    return res;
}

void Graph::addEdge(Vertex u, Vertex v, double weight) {
    if (!hasVertex(u)) addVertex(u);
    if (!hasVertex(v)) addVertex(v);
    adj_[u][v] = weight;
    if (!directed_) adj_[v][u] = weight;
}

void Graph::removeEdge(Vertex u, Vertex v) {
    adj_[u].erase(v);
    if (!directed_) adj_[v].erase(u);
}

bool Graph::hasEdge(Vertex u, Vertex v) const {
    auto it = adj_.find(u);
    if (it == adj_.end()) return false;
    return it->second.find(v) != it->second.end();
}

size_t Graph::edgeCount() const {
    size_t count = 0;
    for (const auto& [_, neigh] : adj_) {
        count += neigh.size();
    }
    return directed_ ? count : count / 2;
}

std::vector<Graph::Edge> Graph::edges() const {
    std::vector<Edge> res;
    for (const auto& [u, neigh] : adj_) {
        for (const auto& [v, _] : neigh) {
            if (directed_ || u <= v) res.emplace_back(u, v);
        }
    }
    return res;
}

std::vector<Graph::Vertex> Graph::neighbors(Vertex v) const {
    auto it = adj_.find(v);
    if (it == adj_.end()) return {};
    std::vector<Vertex> res;
    res.reserve(it->second.size());
    for (const auto& [nei, _] : it->second) res.push_back(nei);
    return res;
}

size_t Graph::degree(Vertex v) const {
    auto it = adj_.find(v);
    return (it == adj_.end()) ? 0 : it->second.size();
}