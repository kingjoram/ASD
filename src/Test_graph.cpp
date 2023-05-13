#include <vector>
#include <queue>
#include <deque>
#include <functional>
#include <cassert>
#include <string>
#include "test_graph.h"
#include "IGraph.h"


std::vector<std::ostream> TestGraph::Test(const IGraph& graph) {
    std::vector<std::string> results;

    results.push_back(BFS(graph));
    results.push_back(DFS(graph));
    results.push_back(TopologicalSort(graph));
}


void TestGraph::BFS(const IGraph& graph, int vertex, std::vector<bool>& visited, std::string& order) {
    std::queue<int> qu;
    qu.push(vertex);
    visited[vertex] = true;

    while (!qu.empty()) {
        int currentVertex = qu.front();
        qu.pop();

        order = order + std::to_string(currentVertex) + " ";

        for (int nextVertex : graph.GetNextVertices(currentVertex)) {
            if (!visited[nextVertex]) {
                visited[nextVertex] = true;
                qu.push(nextVertex);
            }
        }
    }
}

std::string TestGraph::BFS(const IGraph& graph) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::string result("");

    for (int i = 0; i < graph.VerticesCount(); i++) {
        if (!visited[i]) {
            BFS(graph, i, visited, result);
        }
    }

    return result;
}

