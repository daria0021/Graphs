#include "parsers/DIMACSParser.hpp"
#include <fstream>
#include <sstream>
#include <regex>

std::unique_ptr<Graph> DIMACSParser::parse(const std::string& filename) {
    auto g = std::make_unique<Graph>(false);
    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Cannot open file");
    std::string line;
    int n = 0;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == 'c') continue;
        if (line[0] == 'p') {
            std::istringstream iss(line);
            std::string p, format;
            iss >> p >> format >> n;
            for (int i = 0; i < n; ++i) g->addVertex(i);
        } else if (line[0] == 'e') {
            std::istringstream iss(line);
            char e; int u, v;
            iss >> e >> u >> v;
            g->addEdge(u-1, v-1);
        }
    }
    return g;
}