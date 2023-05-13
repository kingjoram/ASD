#ifndef SRC_LIST_GRAPH_H_
#define SRC_LIST_GRAPH_H_

#include <vector>
#include "IGraph.h"

struct ListGraph : public IGraph {
public:
    ~ListGraph();

    ListGraph(int size);
    ListGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> adjacencyLists;
};

#endif // SRC_LIST_GRAPH_H_