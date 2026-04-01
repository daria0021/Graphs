#ifndef SNAPPARSER_HPP
#define SNAPPARSER_HPP

#include "Parser.hpp"

class SNAPParser : public Parser {
public:
    std::unique_ptr<Graph> parse(const std::string& filename) override;
};

#endif