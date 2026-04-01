cmake_minimum_required(VERSION 3.10)
project(GraphoDro4 VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основная библиотека
add_library(graph_lib
        src/Graph.cpp
        src/Metrics.cpp
        src/algorithms/BiconnectedComponents.cpp
        src/algorithms/DFSVisitor.cpp
        src/generators/CompleteGraphGenerator.cpp
        src/generators/CompleteBipartiteGenerator.cpp
        src/generators/TreeGenerator.cpp
        src/generators/StarGenerator.cpp
        src/generators/CycleGenerator.cpp
        src/generators/PathGenerator.cpp
        src/generators/WheelGenerator.cpp
        src/generators/RandomGraphGenerator.cpp
        src/generators/CubicGraphGenerator.cpp
        src/generators/FixedComponentsGenerator.cpp
        src/generators/FixedBridgesGenerator.cpp
        src/generators/FixedArticulationPointsGenerator.cpp
        src/generators/FixedTwoBridgesGenerator.cpp
        src/generators/HalinGraphGenerator.cpp
        src/parsers/EdgeListParser.cpp
        src/parsers/AdjacencyMatrixParser.cpp
        src/parsers/DIMACSParser.cpp
        src/parsers/SNAPParser.cpp
        src/serializers/GraphVizSerializer.cpp
        src/serializers/Program4YouSerializer.cpp
)

target_include_directories(graph_lib PUBLIC include)

# Исполняемый файл
add_executable(GraphoDro4 src/main.cpp)
target_link_libraries(GraphoDro4 graph_lib)

# Тесты (Catch2)
include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(tests
        tests/test_graph.cpp
        tests/test_metrics.cpp
        tests/test_generators.cpp
)
target_link_libraries(tests Catch2::Catch2WithMain graph_lib)