#include <catch2/catch.hpp>
#include "generators/CompleteGraphGenerator.hpp"

TEST_CASE("Complete graph generator", "[generators]") {
    CompleteGraphGenerator gen(5);
    auto g = gen.generate();
    REQUIRE(g->vertexCount() == 5);
    REQUIRE(g->edgeCount() == 10);
    REQUIRE(g->degree(0) == 4);
}