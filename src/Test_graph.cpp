#include <vector>
#include <queue>
#include <deque>
#include <functional>
#include <cassert>
#include <string>
#include "test_graph.h"
#include "IGraph.h"
#include <iostream>

std::vector<std::string> TestGraph::Test(const IGraph& graph) {
    std::vector<std::string> results;


    results.push_back(BFS(graph));
    results.push_back(DFS(graph));
    results.push_back(TopologicalSort(graph));

    return results;
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

    for (int i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            BFS(graph, i, visited, result);
        }
    }

    return result;
}



void TestGraph::DFS(const IGraph & graph, int vertex, std::vector<bool>&visited, std::string & order) {
    visited[vertex] = true;
    order = order + std::to_string(vertex) + " ";

    for (int nextVertex : graph.GetNextVertices(vertex))
    {
        if (!visited[nextVertex])
            DFS(graph, nextVertex, visited, order);
    }
}

std::string TestGraph::DFS(const IGraph& graph) {
    std::string result("");
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            DFS(graph, i, visited, result);
        }
    }


    return result;
}



void TestGraph::TopologicalSort(const IGraph& graph, int vertex, std::vector<bool>& visited, std::deque<int>& sorted) {
    visited[vertex] = true;

    for (int nextVertex : graph.GetNextVertices(vertex)) {
        if (!visited[nextVertex]) {
            TopologicalSort(graph, nextVertex, visited, sorted);
        }
    }

    sorted.push_front(vertex);
}

std::string TestGraph::TopologicalSort(const IGraph& graph) {
    std::deque<int> sorted;
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            TopologicalSort(graph, i, visited, sorted);
        }
    }

    std::string result("");

    while (!sorted.empty()) {
        result = result + std::to_string(sorted.front()) + " ";
        sorted.pop_front();
    }

    return result;
}
