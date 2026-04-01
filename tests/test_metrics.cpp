#include <catch2/catch.hpp>
#include "Graph.hpp"
#include "Metrics.hpp"

TEST_CASE("Metrics on complete graph", "[metrics]") {
    Graph g;
    for (int i = 0; i < 5; ++i) g.addVertex(i);
    for (int i = 0; i < 5; ++i)
        for (int j = i+1; j < 5; ++j)
            g.addEdge(i, j);
    REQUIRE(Metrics::density(g) == 1.0);
    REQUIRE(Metrics::diameter(g) == 1);
    REQUIRE(Metrics::connectedComponents(g) == 1);
    REQUIRE(Metrics::isBipartite(g) == false);
}