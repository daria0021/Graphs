#ifndef EDGELISTPARSER_HPP
#define EDGELISTPARSER_HPP

#include "Parser.hpp"

class EdgeListParser : public Parser {
public:
    std::unique_ptr<Graph> parse(const std::string& filename) override;
};

#endif