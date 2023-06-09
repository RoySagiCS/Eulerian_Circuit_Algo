#pragma once
#include "Graph.h"
#include "UndirectedGraphNode.h"

class UndirectedGraph : public Graph
{
public:
	UndirectedGraph(int i_NumberOfNodes);
	virtual void AddEdge(int node1, int node2)override;
	virtual bool IsEulerian();
	bool AreAllDegreesEven();
	bool IsConnected();
	virtual void MarkUsedEdge(int v, int u);
	virtual	void CopyEdge(int node1, int node2);
	void AddCopiedEdge(int node1, int node2);




	~UndirectedGraph();

private:

};

