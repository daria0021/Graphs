#ifndef GRAPH_EXCEPTION_HPP
#define GRAPH_EXCEPTION_HPP

#include <stdexcept>
#include <string>

class GraphException : public std::runtime_error {
public:
    explicit GraphException(const std::string& msg) : std::runtime_error(msg) {}
};

#endif