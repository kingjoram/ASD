#include <iostream>
#include <string>
#include <vector>
#include "test_graph.h"
#include "IGraph.h"
#include "gtest/gtest.h"


TEST(Graphs, graphs) {
    ListGraph listGraph(9);

    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 5);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 5);
    listGraph.AddEdge(1, 6);
    listGraph.AddEdge(3, 2);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(5, 4);
    listGraph.AddEdge(5, 6);
    listGraph.AddEdge(6, 4);
    listGraph.AddEdge(7, 8);

    std::vector<std::string> result;
    std::vector<std::string> excpected;

    excpected.push_back("0 1 5 2 3 6 4 7 8");
    excpected.push_back("0 1 2 3 4 6 5 7 8");
    excpected.push_back("7 8 0 1 5 3 6 4 2");

    TestGraph tests;
    
    result = tests.Test(listGraph);



    for (int i = 0; i < result.size(); ++i) {
        ASSERT_EQ(excpected[i], result[i]);
    }
}