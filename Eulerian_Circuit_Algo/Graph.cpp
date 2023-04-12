#include "Graph.h"

Graph::Graph(int i_NumberOfNodes)
{
	this->m_Size = i_NumberOfNodes;
	this->m_Graph.resize(i_NumberOfNodes + 1);
}

void Graph::AddEdge(int node1, int node2)
{
}

Graph::~Graph()
{
}

