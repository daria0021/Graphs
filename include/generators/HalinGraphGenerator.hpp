#ifndef HALINGRAPHGENERATOR_HPP
#define HALINGRAPHGENERATOR_HPP

#include "Generator.hpp"

class HalinGraphGenerator : public Generator {
public:
    HalinGraphGenerator(int n);
    std::unique_ptr<Graph> generate() override;
private:
    int n_;
};

#endif