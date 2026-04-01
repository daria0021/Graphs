#ifndef DIMACSPARSER_HPP
#define DIMACSPARSER_HPP

#include "Parser.hpp"

class DIMACSParser : public Parser {
public:
    std::unique_ptr<Graph> parse(const std::string& filename) override;
};

#endif