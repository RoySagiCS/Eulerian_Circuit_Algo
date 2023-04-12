#pragma once
#include "Graph.h"
#include "DirectedGraphNode.h"
class DirectedGraph : public Graph
{
public:
	DirectedGraph(int i_NumberOfNodes);
	virtual void AddEdge(int node1, int node2);

	~DirectedGraph();

private:

};

