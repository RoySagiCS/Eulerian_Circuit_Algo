#pragma once
#include <vector>
#include "GraphNode.h"

class GraphNode;

class Graph
{
public:
	Graph(int i_NumberOfNodes);
	virtual void AddEdge(int node1,int node2);
	virtual bool IsEulerian();
	void Visit(int i_Node);
	std::vector<GraphNode*>* GetGraph();
	~Graph();

protected:
	std::vector<GraphNode*> m_Graph;
	int m_Size;
};

