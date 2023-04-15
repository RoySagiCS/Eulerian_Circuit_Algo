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
	std::list<int> FindCircuit(Graph& graph, int v0);
	std::list<int> EulerListFinder(char i_IsDirected);
	Graph* CopyGraph(char i_IsDirected);
	virtual void CopyEdge(int node1,int node2);
	virtual void MarkUsedEdge(int v, int u);
	int ThereIsNeighborInList(Graph& graph, std::list<int>& L, std::list<int>::iterator& currentIterator);

	~Graph();

protected:
	std::vector<GraphNode*> m_Graph;
	int m_Size;
};

