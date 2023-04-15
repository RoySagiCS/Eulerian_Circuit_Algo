#include <iostream>
#include <vector>
#include <utility>
#include "GraphFactory.h"
#include <vector>
#include <list>
#include "Validator.h"
int main() {
    char isDirected;
    int n, m;
    //std::vector<std::vector<int>> graph;
    Graph* graph;
    GraphFactory factory;
    Validator validator;
    // Print "Is the graph directed: y/n"
    std::cout << "Is the graph directed: y/n" << std::endl;

    // Accept input: y/n for directed or undirected graph
    std::cin >> isDirected;

    // Accept input: number of nodes
    std::cin >> n;

    // Initialize the graph with an empty adjacency list for each node
    graph = factory.CreateGraph(isDirected, n);

    // Accept input: number of edges
    std::cin >> m;

    if (!(validator.ValidateNandM(n,m)))
    {
        validator.PrintNotValid();
        exit(1);
    }

    // Accept pairs of integers representing edges
    for (int i = 0; i < m; ++i) {
        int node1, node2;
        std::cin >> node1 >> node2;

        if (validator.ValidateEdges(node1,node2,n))
        {
            // Add the edge from node1 to node2
            graph->AddEdge(node1, node2);
        }
        else
        {
            validator.PrintNotValid();
            exit(1);

        }

    }

    

    if (graph->IsEulerian())
    {
        std::cout << "The graph is aulerian" << std::endl;

        std::list<int> L = graph->EulerListFinder(isDirected);
        std::list<int>::iterator it2 = L.begin();
        std::cout << "(";

        for (it2; it2 != L.end(); ++it2)
        {

            if (it2 == (--L.end()))
            {
                break;
            }
            std::cout << *it2 << ",";
        }
        std::cout << (*--L.end()) << ")";

    } 
    else
    {
        std::cout << "The graph is NOT aulerian";

    }

    std::list<int> L = graph->EulerListFinder(isDirected);



    return 0;
}