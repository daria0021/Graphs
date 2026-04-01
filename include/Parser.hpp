#ifndef PARSER_HPP
#define PARSER_HPP

#include "Graph.hpp"
#include <memory>
#include <string>

class Parser {
public:
    virtual ~Parser() = default;
    virtual std::unique_ptr<Graph> parse(const std::string& filename) = 0;
};

#endif