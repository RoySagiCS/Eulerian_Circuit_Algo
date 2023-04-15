#include "Graph.h"
#include "GraphFactory.h"

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

std::list<int> Graph::FindCircuit(Graph& graph, int v0)
{
	std::list<int> L;
	L.push_back(v0); // add v0 to the list L

	int v = v0; // initialize v as v0

	do
	{
		std::list<int> neighbors = static_cast<GraphNode*>(graph.m_Graph[v])->GetNeighborsList();
		int u = *(neighbors.begin());
		graph.MarkUsedEdge(v,u);
		L.push_back(u);
		v = u;
	} while (!((graph.m_Graph[v])->GetNeighborsList().empty()));

	return L;

}

Graph* Graph::CopyGraph(char i_IsDirected)
{
	GraphFactory factory;

	Graph* result = factory.CreateGraph(i_IsDirected, this->m_Size);

	std::vector<GraphNode*>::iterator it = this->m_Graph.begin();
	it++;
	for (it; it != this->m_Graph.end(); it++)
	{
		std::list<int> neighbors = m_Graph[(*it)->GetNodeNumber()]->GetNeighborsList();
		std::list<int>::iterator it2 = neighbors.begin();

		for (it2; it2 != neighbors.end(); ++it2)
		{
			result->CopyEdge((*it)->GetNodeNumber(), (*it2));
		}
	}
	return result;
}

void Graph::CopyEdge(int node1, int node2)
{
}

std::list<int> Graph::EulerListFinder(char i_IsDirected)
{
	std::list<int> L;
	Graph* G = this->CopyGraph(i_IsDirected);

	L = this->FindCircuit(*G,1);
	int v;

	std::list<int>::iterator currentPlaceInL = L.begin();


	while ((v = this->ThereIsNeighborInList(*G,L, currentPlaceInL)))
	{
		std::list<int> L1 = this->FindCircuit(*G, v);
		auto prev = currentPlaceInL;
		prev--;
		//L.erase(currentPlaceInL);
		L1.pop_back();
		//std::list<int>::iterator tmpIterator = currentPlaceInL;
		L.splice(currentPlaceInL, L1);
		prev = prev++;
		currentPlaceInL = prev;
	}

	return L;
}

void Graph::MarkUsedEdge(int v, int u)
{
}

int Graph::ThereIsNeighborInList(Graph& graph,std::list<int>& L, std::list<int>::iterator& currentIterator)
{
	int v;
	for (currentIterator; currentIterator != L.end(); currentIterator++)
	{
		if (!(graph.m_Graph[*currentIterator]->GetNeighborsList().empty()))
		{
			return *currentIterator;
		}
	}
	return 0;
}


std::vector<GraphNode*>* Graph::GetGraph()
{
	return &this->m_Graph;
}

Graph::~Graph()
{
}

