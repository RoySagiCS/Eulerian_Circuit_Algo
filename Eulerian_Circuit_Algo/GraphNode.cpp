#include "GraphNode.h"
GraphNode::GraphNode(int i_nodeNumber)
{
	this->m_nodeNumber = i_nodeNumber;
}

int GraphNode::GetNodeNumber()  const
{
	return this->m_nodeNumber;
}

void GraphNode::AddNeighbor(int node2)
{

}

e_Colour GraphNode::GetColour()
{
	return this->m_CurrentColour;
}

void GraphNode::SetColour(e_Colour i_newColour)
{
	this->m_CurrentColour = i_newColour;
}

std::list<int> GraphNode::GetNeighborsList()
{
	return this->m_Neighbors;
}

void GraphNode::RemoveNeighbor(int i_NeighborToRemove)
{
	std::list<int>::iterator it = this->m_Neighbors.begin();
	for (it; it != this->m_Neighbors.end(); ++it) {

		if (*it == i_NeighborToRemove)
		{
			this->m_Neighbors.erase(it);
			break;
		}
	}
}

GraphNode::~GraphNode()
{
}

