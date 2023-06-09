#pragma once
#include "GraphNode.h"
class DirectedGraphNode : public GraphNode
{
public:
	DirectedGraphNode(int i_nodeNumber);
	int GetDin() const;
	int GetDout() const;
	void AddDin();
	void AddDout();
	virtual void AddNeighbor(int node2);
	~DirectedGraphNode();

private:
	int m_Din = 0;
	int m_Dout = 0;

};

