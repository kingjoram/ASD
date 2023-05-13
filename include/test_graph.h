#ifndef SRC_TEST_GRAPH_H_
#define SRC_TEST_GRAPH_H_

#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <IGraph.h>

class TestGraph {
public: 
    std::vector<std::string> Test(const IGraph& graph);


    std::string BFS(const IGraph& graph);

    std::string DFS(const IGraph& graph);

    std::string TopologicalSort(const IGraph& graph);
private:
    void BFS(const IGraph& graph, int vertex, std::vector<bool>& visited, std::string& order);


    void DFS(const IGraph& graph, int vertex, std::vector<bool>& visited, std::string& order);


    void TopologicalSort(const IGraph& graph, int vertex, std::vector<bool>& visited, std::deque<int>& sorted);
};

#endif // SRC_TEST_GRAPH_H_