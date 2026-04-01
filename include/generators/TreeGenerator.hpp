#ifndef TREEGENERATOR_HPP
#define TREEGENERATOR_HPP

#include "Generator.hpp"

class TreeGenerator : public Generator {
public:
    TreeGenerator(int n);
    std::unique_ptr<Graph> generate() override;
private:
    int n_;
};

#endif