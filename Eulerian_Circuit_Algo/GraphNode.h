#pragma once
#include <list>
class GraphNode
{
public:
	GraphNode(int i_nodeNumber);
	int GetNodeNumber() const;
	~GraphNode();

private:
	int m_nodeNumber;
	std::list<int> m_Neighbors;
};

