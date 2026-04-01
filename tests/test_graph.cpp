#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "Graph.hpp"

TEST_CASE("Graph basic operations", "[graph]") {
    Graph g;
    g.addVertex(1);
    g.addVertex(2);
    g.addEdge(1, 2);
    REQUIRE(g.hasVertex(1));
    REQUIRE(g.hasVertex(2));
    REQUIRE(g.hasEdge(1, 2));
    REQUIRE(g.edgeCount() == 1);
}