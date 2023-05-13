#include <vector>
#include <cassert>
#include <set>
#include "set_graph.h"


SetGraph::SetGraph(int size) {
    arrayOfSets.resize(size);
}

SetGraph::SetGraph(const IGraph & graph) {
    arrayOfSets.resize(graph.VerticesCount());

    for (int i = 0; i < graph.VerticesCount(); ++i) {
        std::vector<int> nextVertices = graph.GetNextVertices(i);

        for (int j = 0; j < nextVertices.size(); ++j) {
            arrayOfSets[i].insert(nextVertices[j]);
        }
    }
}

SetGraph::~SetGraph() {

}


void SetGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < arrayOfSets.size());
    assert(0 <= to && to < arrayOfSets.size());

    arrayOfSets[from].insert(to);
}


int SetGraph::VerticesCount() const {
    return arrayOfSets.size();
}


std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < arrayOfSets.size());

    std::vector<int> nextVetrices;
    for (int element: arrayOfSets[vertex]) {
        nextVetrices.push_back(element);
    }

    return nextVetrices;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < arrayOfSets.size());

    std::vector<int> prevVertices;

    for (int from = 0; from < arrayOfSets.size(); ++from) {
        for (int to : arrayOfSets[from]) {
            if (to == vertex) {
                prevVertices.push_back(from);
            }
        }
    }

    return prevVertices;
}
