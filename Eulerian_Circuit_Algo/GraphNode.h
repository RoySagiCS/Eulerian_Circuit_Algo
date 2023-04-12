#pragma once
#include <list>

enum e_Colour
{
	WHITE = 0,
	GRAY = 1,
	BLACK = 2
};

class GraphNode
{
public:
	GraphNode(int i_nodeNumber);
	int GetNodeNumber() const;
	virtual void AddNeighbor(int node2);
	e_Colour GetColour();
	void SetColour(e_Colour i_newColour);
	std::list<int> GetNeighborsList();
	~GraphNode();

protected:
	int m_nodeNumber;
	std::list<int> m_Neighbors;
	e_Colour m_CurrentColour = WHITE;
};

