#ifndef COMPLETEGRAPHGENERATOR_HPP
#define COMPLETEGRAPHGENERATOR_HPP

#include "Generator.hpp"

class CompleteGraphGenerator : public Generator {
public:
    CompleteGraphGenerator(int n);
    std::unique_ptr<Graph> generate() override;
private:
    int n_;
};

#endif