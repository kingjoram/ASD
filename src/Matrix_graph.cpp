#include <vector>
#include <cassert>
#include "matrix_graph.h"


MatrixGraph::~MatrixGraph() {
    
}

MatrixGraph::MatrixGraph(int verticesCount) {
    matrix.resize(verticesCount);
    for (int i = 0; i < verticesCount; ++i) {
        matrix[i].resize(verticesCount, 0);
    }
}

MatrixGraph::MatrixGraph(const IGraph& graph) {
    matrix.resize(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        matrix[i].resize(graph.VerticesCount(), 0);
    }


    for (int i = 0; i < matrix.size(); ++i) {
        std::vector<int> ithNextVertices = graph.GetNextVertices(i);

        for (int j = 0; j < ithNextVertices.size(); ++j) {
            matrix[i][ithNextVertices[j]] = 1;
        }
    }
}


void MatrixGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < matrix.size());
    assert(0 <= to && to < matrix.size());

    matrix[from][to] = 1;
}


int MatrixGraph::VerticesCount() const {
    return matrix.size();
}



std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < matrix.size());

    std::vector<int> nextVertices;

    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[vertex][i]) {
            nextVertices.push_back(i);
        }
    }

    return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < matrix.size());

    std::vector<int> nextVertices;

    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][vertex]) {
            nextVertices.push_back(i);
        }
    }

    return nextVertices;
}
