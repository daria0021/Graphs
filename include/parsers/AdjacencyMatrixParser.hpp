#ifndef ADJACENCYMATRIXPARSER_HPP
#define ADJACENCYMATRIXPARSER_HPP

#include "Parser.hpp"

class AdjacencyMatrixParser : public Parser {
public:
    std::unique_ptr<Graph> parse(const std::string& filename) override;
};

#endif