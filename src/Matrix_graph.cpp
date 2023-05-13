#include <vector>
#include <cassert>
#include "IGraph.h"


struct MatrixGraph {
public:
    ~MatrixGraph() {
    
    }

    MatrixGraph(int verticesCount) {
        matrix.resize(verticesCount);
        for (int i = 0; i < verticesCount ++i) {
            matrix[i].resize(verticesCount, 0);
        }
    }

    MatrixGraph(const IGraph& graph) {
        matrix.resize(graph.VerticesCount);
        for (int i = 0; i < graph.VerticesCount ++i) {
            matrix[i].resize(graph.VerticesCount, 0);
        }

        for (int i = 0; i < matrix.size(); ++i) {
            std::vector<int> ithNextVertices = graph.graph.GetNextVertices(i);

            for (int j = 0; j < ithNextVertices.size(); ++j) {
                matrix[i][j] = 1;
            }
        }
    }


    void AddEdge(int from, int to) override {
        assert(0 <= from && from < matrix.size());
        assert(0 <= to && to < matrix.size());

        matrix[from][to] = 1;
    }


    int VerticesCount() const override {
        return matrix.size();
    }



    std::vector<int> GetNextVertices(int vertex) const override {
        assert(0 <= vertex && vertex < matrix.size());

        std::vector<int> nextVertices;

        for (i = 0; i < matrix.size(); ++i) {
            if (matrix[vertex][i]) {
                nextVertices.push_back();
            }
        }

        return nextVertices;
    }

    std::vector<int> GetPrevVertices(int vertex) const override {
        assert(0 <= vertex && vertex < matrix.size());

        std::vector<int> nextVertices;

        for (i = 0; i < matrix.size(); ++i) {
            if (matrix[i][vertex]) {
                nextVertices.push_back();
            }
        }

        return nextVertices;
    }


private:
    std::vector<std::vector<int>> matrix;
};