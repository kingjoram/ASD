#include <vector>
#include <cassert>
#include "IGraph.h"


struct ArcGraph : public IGraph {
public:
    ~ArcGraph() {
    
    }

    ArcGraph(const IGraph& graph) {
        verticesCount = graph.VerticesCount();

        for (int i = 0; i < verticesCount; ++i) {
            std::vector<int> ithArcs = graph.GetNextVertices(i);

            for (int j = 0; j < ithArcs.size(); ++j) {
                arcs.push_back(i, ithArcs[j]);
            }
        }
    }

    ArcGraph(const int verticesCount) {
        this->verticesCount = verticesCount;
    }

    void AddEdge(int from, int to) override {
        assert(0 <= from && from < verticesCount);
        assert(0 <= to && to < verticesCount);

        arcs.push_back(from, to);
    }


    int VerticesCount() const override {
        return verticesCount;
    }


    std::vector<int> GetNextVertices(int vertex) const override {
        assert(0 <= vertex && vertex < verticesCount);

        std::vector<int> nextVerices;

        for (int i = 0; i < arcs.size(); ++i) {
            if (arcs[i].first == vertex) {
                nextVerices.push_back(arcs[i].second);
            }
        }

        return nextVerices;
    }

    std::vector<int> GetPrevVertices(int vertex) const override {
        assert(0 <= vertex && vertex < verticesCount);

        std::vector<int> prevVerices;

        for (int i = 0; i < arcs.size(); ++i) {
            if (arcs[i].second == vertex) {
                prevVerices.push_back(arcs[i].first);
            }
        }

        return nextVerices;
    }


private:
    std::vector<std::pair<int, int>> arcs;
    int verticesCount;
};