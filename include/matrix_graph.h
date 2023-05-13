#ifndef SRC_MATRIX_GRAPH_H_
#define SRC_MATRIX_GRAPH_H_

#include <vector>
#include "IGraph.h"

struct MatrixGraph : public IGraph {
public:
    ~MatrixGraph();

    MatrixGraph(int verticesCount);
    MatrixGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> matrix;
};

#endif // SRC_MATRIX_GRAPH_H_