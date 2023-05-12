#include <vector>
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
        if (from >= 0 && from < VerticesCount() && to >= 0 && to < VerticesCount()) {
            arcs.push_back(from, to);
        }
    }


    int VerticesCount() const override {
        return verticesCount;
    }


    std::vector<int> GetNextVertices(int vertex) const override {
        std::vector<int> nextVerices;


        for (int i = 0; i < arcs.size(); ++i) {
            if (arcs[i].first == vertex) {
                nextVerices.push_back(arcs[i].second);
            }
        }

        return nextVerices;
    }

    std::vector<int> GetPrevVertices(int vertex) const override {
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