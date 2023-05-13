#ifndef SRC_ARC_GRAPH_H_
#define SRC_ARC_GRAPH_H_

#include <vector>
#include "IGraph.h"

struct ArcGraph : public IGraph{
public:
    ~ArcGraph();

    ArcGraph(int verticesCount);
    ArcGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::pair<int, int>> arcs;
    int verticesCount;
};

#endif // SRC_ARC_GRAPH_H_