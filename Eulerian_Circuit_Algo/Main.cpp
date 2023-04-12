#include <iostream>
#include <vector>
#include <utility>
#include "GraphFactory.h"

int main() {
    char isDirected;
    int n, m;
    //std::vector<std::vector<int>> graph;
    Graph* graph;
    GraphFactory factory;

    // 1. Print "Is the graph directed: y/n"
    std::cout << "Is the graph directed: y/n" << std::endl;

    // 2.1. Accept input: y/n for directed or undirected graph
    std::cin >> isDirected;

    // 2.2. Accept input: number of nodes
    std::cin >> n;

    // Initialize the graph with an empty adjacency list for each node
    graph = factory.CreateGraph(isDirected, n);

    // 2.3. Accept input: number of edges
    std::cin >> m;

    // 2.4. Accept pairs of integers representing edges
    for (int i = 0; i < m; ++i) {
        int node1, node2;
        std::cin >> node1 >> node2;

        // Add the edge from node1 to node2
       
        graph->AddEdge(node1,node2);


    }

  

    if (graph->IsEulerian())
    {
        std::cout << "yey";
    } 
    else
    {
        std::cout << "Ney";

    }

    //// Print the adjacency list
    //for (int i = 0; i < n; ++i) {
    //    std::cout << "Node " << i + 1 << ": ";
    //    for (int neighbor : graph[i]) {
    //        std::cout << neighbor << " ";
    //    }
    //    std::cout << std::endl;
    //}

    return 0;
}




//int main() {
//    char is_directed;
//    int n, m;
//    std::vector<std::vector<int>> graph;
//
//    // 1. Print "Is the graph directed: y/n"
//    std::cout << "Is the graph directed: y/n" << std::endl;
//
//    // 2.1. Accept input: y/n for directed or undirected graph
//    std::cin >> is_directed;
//
//    // 2.2. Accept input: number of nodes
//    std::cin >> n;
//
//    // Initialize the graph with an empty adjacency list for each node
//    graph.resize(n);
//
//    // 2.3. Accept input: number of edges
//    std::cin >> m;
//
//    // 2.4. Accept pairs of integers representing edges
//    for (int i = 0; i < m; ++i) {
//        int node1, node2;
//        std::cin >> node1 >> node2;
//
//        // Add the edge from node1 to node2
//        graph[node1 - 1].push_back(node2);
//
//        // If the graph is undirected, also add the edge from node2 to node1
//        if (is_directed == 'n') {
//            graph[node2 - 1].push_back(node1);
//        }
//    }
//
//    // Print the adjacency list
//    for (int i = 0; i < n; ++i) {
//        std::cout << "Node " << i + 1 << ": ";
//        for (int neighbor : graph[i]) {
//            std::cout << neighbor << " ";
//        }
//        std::cout << std::endl;
//    }
//
//    return 0;
//}

