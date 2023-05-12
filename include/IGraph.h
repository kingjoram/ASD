#ifndef SRC_IGRAPH_H_
#define SRC_IGRAPH_H_

#include <vector>

struct IGraph {
    virtual ~IGraph() {}

    // ���������� ����� �� from � to.
    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

#endif // SRC_IGRAPH_H_