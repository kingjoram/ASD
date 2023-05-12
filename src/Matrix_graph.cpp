#include <vector>
#include "IGraph.h"


struct MatrixGraph {
public:
    ~MatrixGraph() {
    
    }

    MatrixGraph(const int verticesCount) {
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
        if (from >= 0 && from < VerticesCount() && to >= 0 && to < VerticesCount()) {
            matrix[from][to] = 1;
        }
    }


    int VerticesCount() const override {
        return matrix.size();
    }



    std::vector<int> GetNextVertices(int vertex) const override {
        std::vector<int> nextVertices;

        for (i = 0; i < matrix.size(); ++i) {
            if (matrix[vertex][i]) {
                nextVertices.push_back();
            }
        }

        return nextVertices;
    }

    std::vector<int> GetPrevVertices(int vertex) const override {
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