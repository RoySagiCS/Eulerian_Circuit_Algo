#include "DirectedGraph.h"
#include "GraphFactory.h"

DirectedGraph::DirectedGraph(int i_NumberOfNodes) : Graph(i_NumberOfNodes)
{
	for (int i = 0; i < m_Size; i++)
	{
		this->m_Graph[i + 1] = new DirectedGraphNode(i + 1);
	}
}

void DirectedGraph::AddEdge(int node1, int node2)
{
	this->m_Graph[node1]->AddNeighbor(node2);
	static_cast<DirectedGraphNode*>(this->m_Graph[node1])->AddDout();
	static_cast<DirectedGraphNode*>(this->m_Graph[node2])->AddDin();

}

bool DirectedGraph::IsEulerian()
{
	this->Visit(1);
	if (!(this->IsStronglyConnected()))
	{
		return false;
	}
	if (!IsDinDoutEqual())
	{
		return false;
	}
	return true;
}

bool DirectedGraph::IsStronglyConnected()
{
	std::vector<GraphNode*>::iterator it = this->m_Graph.begin();
	it++;
	for (it; it != this->m_Graph.end(); it++)
	{
		if ((*it)->GetColour() == WHITE)
		{
			return false;
		}
	}

	CreateTransposeGraph();
	this->m_transposedGraph->Visit(1);

	std::vector<GraphNode*>::iterator it2 = this->m_transposedGraph->GetGraph()->begin();
	it2++;
	for (it2; it2 != this->m_transposedGraph->GetGraph()->end(); it2++)
	{
		if ((*it2)->GetColour() == WHITE)
		{
			return false;
		}
	}
	return true;
}

void DirectedGraph::CreateTransposeGraph()
{
	GraphFactory factory;
	this->m_transposedGraph = factory.CreateGraph('y', this->m_Size);

	std::vector<GraphNode*>::iterator it = this->m_Graph.begin();
	it++;
	for (it; it != this->m_Graph.end(); it++)
	{
		std::list<int> neighbors = m_Graph[(*it)->GetNodeNumber()]->GetNeighborsList();
		std::list<int>::iterator it2 = neighbors.begin();

		for (it2; it2 != neighbors.end(); ++it2) 
		{
			this->m_transposedGraph->AddEdge((*it2), (*it)->GetNodeNumber());
		}
	}

}

bool DirectedGraph::IsDinDoutEqual()
{
	std::vector<GraphNode*>::iterator it = this->m_Graph.begin();
	it++;

	for (it; it != this->m_Graph.end(); it++)
	{
		if (static_cast<DirectedGraphNode*>(*it)->GetDin() != static_cast<DirectedGraphNode*>(*it)->GetDout())
		{
			return false;
		}
	}
	return true;
}


DirectedGraph::~DirectedGraph()
{
}

