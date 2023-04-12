#include "UndirectedGraph.h"


UndirectedGraph::UndirectedGraph(int i_NumberOfNodes) : Graph(i_NumberOfNodes)
{
	for (int i = 0; i < m_Size; i++)
	{
		this->m_Graph[i + 1] = new UndirectedGraphNode(i + 1);
	}
}

UndirectedGraph::~UndirectedGraph()
{
}

