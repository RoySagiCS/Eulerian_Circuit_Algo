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
}

void DirectedGraphNode::AddDout()
{
}

DirectedGraphNode::~DirectedGraphNode()
{
}

