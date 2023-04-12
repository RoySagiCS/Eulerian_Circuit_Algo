#include "Graph.h"

Graph::Graph(int i_NumberOfNodes)
{
	this->m_Size = i_NumberOfNodes;
	this->m_Graph.resize(i_NumberOfNodes + 1);
}

void Graph::AddEdge(int node1, int node2)
{
}

bool Graph::IsEulerian()
{
	return false;
}

void Graph::Visit(int i_Node)
{
	this->m_Graph[i_Node]->SetColour(GRAY);
	std::list<int> neighbors = m_Graph[i_Node]->GetNeighborsList();
	std::list<int>::iterator it = neighbors.begin();

	for (it ; it != neighbors.end(); ++it) {

		if (m_Graph[*it]->GetColour() == WHITE)
		{
			Visit(*it);
		}
	}
	this->m_Graph[i_Node]->SetColour(BLACK);

}

std::vector<GraphNode*>* Graph::GetGraph()
{
	return &this->m_Graph;
}

Graph::~Graph()
{
}

