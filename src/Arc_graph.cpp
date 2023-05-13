#include <vector>
#include <cassert>
#include "arc_graph.h"


ArcGraph::~ArcGraph() {
    
}

ArcGraph::ArcGraph(const IGraph& graph) {
    verticesCount = graph.VerticesCount();

    for (int i = 0; i < verticesCount; ++i) {
        std::vector<int> ithArcs = graph.GetNextVertices(i);

        for (int j = 0; j < ithArcs.size(); ++j) {
            std::pair<int, int> pair(i, ithArcs[j]);
            arcs.push_back(pair);
        }
    }
}

ArcGraph::ArcGraph(int verticesCount) {
    this->verticesCount = verticesCount;
}

void ArcGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < verticesCount);
    assert(0 <= to && to < verticesCount);

    std::pair<int, int> pair(from, to);
    arcs.push_back(pair);
}


int ArcGraph::VerticesCount() const {
    return verticesCount;
}


std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < verticesCount);

    std::vector<int> nextVerices;

    for (int i = 0; i < arcs.size(); ++i) {
        if (arcs[i].first == vertex) {
            nextVerices.push_back(arcs[i].second);
        }
    }

    return nextVerices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < verticesCount);

    std::vector<int> prevVerices;

    for (int i = 0; i < arcs.size(); ++i) {
        if (arcs[i].second == vertex) {
            prevVerices.push_back(arcs[i].first);
        }
    }

    return prevVerices;
}
