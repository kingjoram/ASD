#ifndef SRC_SET_GRAPH_H_
#define SRC_SET_GRAPH_H_

#include <vector>
#include <set>
#include "IGraph.h"

struct SetGraph : public IGraph {
public:
    ~SetGraph();

    SetGraph(int size);
    SetGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::set<int>> arrayOfSets;
};

#endif // SRC_SET_GRAPH_H_