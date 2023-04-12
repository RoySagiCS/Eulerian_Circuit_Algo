#pragma once
#include "Graph.h"
#include "DirectedGraph.h"
#include "UndirectedGraph.h"

class GraphFactory
{
public:
	GraphFactory();
	Graph* CreateGraph(char i_Context, int i_GraphSize); // context- Directed/undirected
	~GraphFactory();

private:

};

