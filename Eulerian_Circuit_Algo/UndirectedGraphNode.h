#pragma once
#include "GraphNode.h"
class UndirectedGraphNode : public GraphNode
{
public:
	UndirectedGraphNode(int i_nodeNumber);
	int GetDegree();
	void AddDegree();
	virtual void AddNeighbor(int node2);
	~UndirectedGraphNode();

private:
	int m_NodeDegree=0;
};

