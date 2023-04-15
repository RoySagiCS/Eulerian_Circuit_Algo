#pragma once
#include "Graph.h"
#include "DirectedGraphNode.h"
class DirectedGraph : public Graph
{
public:
	DirectedGraph(int i_NumberOfNodes);
	virtual void AddEdge(int node1, int node2) override;
	virtual bool IsEulerian();
	bool IsStronglyConnected();
	bool IsDinDoutEqual();
	void CreateTransposeGraph();
	virtual void MarkUsedEdge(int v, int u);
	virtual void CopyEdge(int node1, int node2);

	~DirectedGraph();

private:
	Graph* m_transposedGraph = nullptr;
};

