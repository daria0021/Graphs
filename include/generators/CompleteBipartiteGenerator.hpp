#ifndef COMPLETEBIPARTITEGENERATOR_HPP
#define COMPLETEBIPARTITEGENERATOR_HPP

#include "Generator.hpp"

class CompleteBipartiteGenerator : public Generator {
public:
    CompleteBipartiteGenerator(int n, int m);
    std::unique_ptr<Graph> generate() override;
private:
    int n_, m_;
};

#endif