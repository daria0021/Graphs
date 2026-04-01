#ifndef WHEELGENERATOR_HPP
#define WHEELGENERATOR_HPP

#include "Generator.hpp"

class WheelGenerator : public Generator {
public:
    WheelGenerator(int n);
    std::unique_ptr<Graph> generate() override;
private:
    int n_;
};

#endif