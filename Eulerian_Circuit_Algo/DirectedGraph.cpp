#include "DirectedGraph.h"


DirectedGraph::DirectedGraph(int i_NumberOfNodes) : Graph(i_NumberOfNodes)
{
	for (int i = 0; i < m_Size; i++)
	{
		this->m_Graph[i + 1] = new DirectedGraphNode(i + 1);
	}
}

void DirectedGraph::AddEdge(int node1, int node2)
{
	this->m_Graph[node1].AddNeighbor();
}

DirectedGraph::~DirectedGraph()
{
}

