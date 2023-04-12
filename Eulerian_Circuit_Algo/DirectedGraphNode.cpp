#include "DirectedGraphNode.h"
DirectedGraphNode::DirectedGraphNode(int i_nodeNumber) : GraphNode(i_nodeNumber)
{

}

int DirectedGraphNode::GetDin() const
{
	return 0;
}

int DirectedGraphNode::GetDout() const
{
	return 0;
}

void DirectedGraphNode::AddDin()
{
	this->m_Din++;
}

void DirectedGraphNode::AddDout()
{
	this->m_Dout++;
}

void DirectedGraphNode::AddNeighbor(int node2)
{
	this->m_Neighbors.push_back(node2);
}

DirectedGraphNode::~DirectedGraphNode()
{
}

