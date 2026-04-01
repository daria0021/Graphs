#include "parsers/AdjacencyMatrixParser.hpp"
#include <fstream>
#include <sstream>
#include <vector>

std::unique_ptr<Graph> AdjacencyMatrixParser::parse(const std::string& filename) {
    auto g = std::make_unique<Graph>(false);
    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Cannot open file");
    std::vector<std::vector<int>> matrix;
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        std::istringstream iss(line);
        std::vector<int> row;
        int val;
        while (iss >> val) row.push_back(val);
        if (!row.empty()) matrix.push_back(row);
    }
    int n = matrix.size();
    if (n == 0) return g;
    for (int i = 0; i < n; ++i) {
        g->addVertex(i);
        for (int j = i+1; j < n; ++j) {
            if (matrix[i][j] != 0) g->addEdge(i, j);
        }
    }
    return g;
}