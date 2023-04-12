#include "UndirectedGraphNode.h"
UndirectedGraphNode::UndirectedGraphNode(int i_nodeNumber) : GraphNode(i_nodeNumber)
{
}

int UndirectedGraphNode::GetDegree()
{
	return this->m_NodeDegree;
}

void UndirectedGraphNode::AddDegree()
{
	this->m_NodeDegree++;
}

void UndirectedGraphNode::AddNeighbor(int node2)
{
	this->m_Neighbors.push_back(node2);
}

UndirectedGraphNode::~UndirectedGraphNode()
{
}


