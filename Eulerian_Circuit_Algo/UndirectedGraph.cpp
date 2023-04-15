#include "UndirectedGraph.h"


UndirectedGraph::UndirectedGraph(int i_NumberOfNodes) : Graph(i_NumberOfNodes)
{
	for (int i = 0; i < m_Size; i++)
	{
		this->m_Graph[i + 1] = new UndirectedGraphNode(i + 1);
	}
}

void UndirectedGraph::AddEdge(int node1, int node2)
{
	static_cast<UndirectedGraphNode*>(this->m_Graph[node1])->AddNeighbor(node2);
	static_cast<UndirectedGraphNode*>(this->m_Graph[node2])->AddNeighbor(node1);
	static_cast<UndirectedGraphNode*>(this->m_Graph[node1])->AddDegree();
	static_cast<UndirectedGraphNode*>(this->m_Graph[node2])->AddDegree();
}

bool UndirectedGraph::IsEulerian()
{
	this->Visit(1);
	if (!(this->IsConnected()))
	{
		return false;
	}
	if (!AreAllDegreesEven())
	{
		return false;
	}
	return true;
}

bool UndirectedGraph::AreAllDegreesEven()
{
	std::vector<GraphNode*>::iterator it = this->m_Graph.begin();
	it++;

	for (it; it != this->m_Graph.end(); it++)
	{
		if (static_cast<UndirectedGraphNode*>(*it)->GetDegree() %2 == 1)
		{
			return false;
		}
	}
	return true;
}

bool UndirectedGraph::IsConnected()
{
	std::vector<GraphNode*>::iterator it = this->m_Graph.begin();
	it++;
	for (it ; it != this->m_Graph.end(); it++)
	{
		if ((*it)->GetColour() == WHITE)
		{
			return false;
		}
	}
	return true;
}

void UndirectedGraph::MarkUsedEdge(int v, int u)
{
	this->m_Graph[v]->RemoveNeighbor(u); 
	this->m_Graph[u]->RemoveNeighbor(v);

}

void UndirectedGraph::CopyEdge(int node1, int node2)
{
	this->AddCopiedEdge(node1, node2);
}

void UndirectedGraph::AddCopiedEdge(int node1, int node2)
{
	static_cast<UndirectedGraphNode*>(this->m_Graph[node1])->AddNeighbor(node2);
	static_cast<UndirectedGraphNode*>(this->m_Graph[node1])->AddDegree();
}

UndirectedGraph::~UndirectedGraph()
{
}

