#pragma once
#include "GraphNode.h"
class UndirectedGraphNode : public GraphNode
{
public:
	UndirectedGraphNode(int i_nodeNumber);
	int GetDegree() const;
	void AddDegree();
	~UndirectedGraphNode();

private:
	int m_NodeDegree=0;
};

