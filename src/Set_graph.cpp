#include <vector>
#include <cassert>
#include <set>
#include "IGraph.h"


struct SetGraph : public IGraph {
public:
    SetGraph(int size) {
        arrayOfSets.resize(size);
    }

    SetGraph(const IGraph& graph) {
        arrayOfSets.resize(graph.VerticesCount());

        for (int i = 0; i < graph.VerticesCount(); ++i) {
            std::vector<int> nextVertices = graph.GetNextVertices();

            for (int j = 0; j < nextVertices.size(); ++j) {
                arrayOfSets[i].insert(nextVertices[j]);
            }
        }
    }

    ~SetGraph() {

    }


    void AddEdge(int from, int to) override {
        assert(0 <= from && from < arrayOfSets.size());
        assert(0 <= to && to < arrayOfSets.size());

        arrayOfSets[from].insert(to);
    }


    int VerticesCount() const override {
        return arrayOfSets.size();
    }


    std::vector<int> GetNextVertices(int vertex) const override {
        assert(0 <= vertex && vertex < arrayOfSets.size());

        std::vector<int> nextVetrices;
        for (int element: arrayOfSets[vertex]) {
            nextVetrices.push_back(element);
        }

        return nextVetrices;
    }

    std::vector<int> GetPrevVertices(int vertex) const override {
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

private:
    std::vector<std::set<int>> arrayOfSets;
};