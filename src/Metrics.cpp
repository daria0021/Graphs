#include "Metrics.hpp"
#include <queue>
#include <algorithm>
#include <limits>
#include <unordered_set>
#include <stack>
#include <functional>
#include <set>
#include <random>

double Metrics::density(const Graph& g) {
    size_t n = g.vertexCount();
    if (n <= 1) return 0.0;
    size_t maxEdges = n * (n - 1) / 2;
    return static_cast<double>(g.edgeCount()) / maxEdges;
}

int Metrics::diameter(const Graph& g) {
    int diam = 0;
    for (auto v : g.vertices()) {
        std::unordered_map<Graph::Vertex, int> dist;
        std::queue<Graph::Vertex> q;
        dist[v] = 0;
        q.push(v);
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            for (auto w : g.neighbors(u)) {
                if (!dist.count(w)) {
                    dist[w] = dist[u] + 1;
                    q.push(w);
                }
            }
        }
        for (auto& [_, d] : dist) {
            diam = std::max(diam, d);
        }
    }
    return diam;
}

double Metrics::transitivity(const Graph& g) {
    if (g.isDirected()) return 0.0;
    std::set<std::pair<Graph::Vertex, Graph::Vertex>> edgeSet;
    for (auto e : g.edges()) {
        edgeSet.insert(e);
    }
    long long triangles = 0;
    long long triads = 0;
    for (auto v : g.vertices()) {
        auto neigh = g.neighbors(v);
        size_t d = neigh.size();
        if (d >= 2) {
            triads += d * (d - 1) / 2;
            for (size_t i = 0; i < d; ++i) {
                for (size_t j = i+1; j < d; ++j) {
                    if (edgeSet.count({neigh[i], neigh[j]}) ||
                        edgeSet.count({neigh[j], neigh[i]})) {
                        ++triangles;
                    }
                }
            }
        }
    }
    if (triads == 0) return 0.0;
    return static_cast<double>(triangles) / triads;
}

int Metrics::connectedComponents(const Graph& g) {
    std::unordered_set<Graph::Vertex> visited;
    int comp = 0;
    for (auto v : g.vertices()) {
        if (visited.count(v)) continue;
        ++comp;
        std::queue<Graph::Vertex> q;
        q.push(v);
        visited.insert(v);
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            for (auto w : g.neighbors(u)) {
                if (!visited.count(w)) {
                    visited.insert(w);
                    q.push(w);
                }
            }
        }
    }
    return comp;
}

int Metrics::articulationPoints(const Graph& g) {
    if (g.isDirected()) return 0;
    std::unordered_map<Graph::Vertex, int> tin, low;
    std::unordered_set<Graph::Vertex> ap;
    int timer = 0;
    std::function<void(Graph::Vertex, Graph::Vertex)> dfs = [&](Graph::Vertex v, Graph::Vertex p) {
        tin[v] = low[v] = ++timer;
        int children = 0;
        for (auto to : g.neighbors(v)) {
            if (to == p) continue;
            if (tin.count(to)) {
                low[v] = std::min(low[v], tin[to]);
            } else {
                dfs(to, v);
                low[v] = std::min(low[v], low[to]);
                if (low[to] >= tin[v] && p != -1) {
                    ap.insert(v);
                }
                ++children;
            }
        }
        if (p == -1 && children > 1) {
            ap.insert(v);
        }
    };
    for (auto v : g.vertices()) {
        if (!tin.count(v)) {
            dfs(v, -1);
        }
    }
    return ap.size();
}

int Metrics::bridges(const Graph& g) {
    if (g.isDirected()) return 0;
    std::unordered_map<Graph::Vertex, int> tin, low;
    int timer = 0;
    int bridges = 0;
    std::function<void(Graph::Vertex, Graph::Vertex)> dfs = [&](Graph::Vertex v, Graph::Vertex p) {
        tin[v] = low[v] = ++timer;
        for (auto to : g.neighbors(v)) {
            if (to == p) continue;
            if (tin.count(to)) {
                low[v] = std::min(low[v], tin[to]);
            } else {
                dfs(to, v);
                low[v] = std::min(low[v], low[to]);
                if (low[to] > tin[v]) {
                    ++bridges;
                }
            }
        }
    };
    for (auto v : g.vertices()) {
        if (!tin.count(v)) {
            dfs(v, -1);
        }
    }
    return bridges;
}

bool Metrics::isBipartite(const Graph& g) {
    if (g.isDirected()) return false;
    std::unordered_map<Graph::Vertex, int> color;
    for (auto v : g.vertices()) {
        if (color.count(v)) continue;
        std::queue<Graph::Vertex> q;
        q.push(v);
        color[v] = 0;
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            for (auto w : g.neighbors(u)) {
                if (!color.count(w)) {
                    color[w] = color[u] ^ 1;
                    q.push(w);
                } else if (color[w] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int Metrics::greedyChromaticNumber(const Graph& g) {
    if (g.isDirected()) return 0;
    std::vector<Graph::Vertex> vertices = g.vertices();
    std::unordered_map<Graph::Vertex, int> color;
    for (auto v : vertices) {
        std::unordered_set<int> used;
        for (auto w : g.neighbors(v)) {
            auto it = color.find(w);
            if (it != color.end()) used.insert(it->second);
        }
        int c = 0;
        while (used.count(c)) ++c;
        color[v] = c;
    }
    int maxColor = 0;
    for (auto& [_, c] : color) maxColor = std::max(maxColor, c);
    return maxColor + 1;
}