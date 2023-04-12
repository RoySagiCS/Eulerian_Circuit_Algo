#include "GraphNode.h"
GraphNode::GraphNode(int i_nodeNumber)
{
	this->m_nodeNumber = i_nodeNumber;
}

int GraphNode::GetNodeNumber()  const
{
	return this->m_nodeNumber;
}

GraphNode::~GraphNode()
{
}

