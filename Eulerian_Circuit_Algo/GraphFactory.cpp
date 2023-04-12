#include "GraphFactory.h"
GraphFactory::GraphFactory()
{
}

Graph* GraphFactory::CreateGraph(char i_Context, int i_GraphSize)
{
	Graph* graph = nullptr;
	if (i_Context == 'y' || i_Context == 'Y')
	{
		graph = new DirectedGraph(i_GraphSize);
	}
	else if (i_Context == 'n' || i_Context == 'N')
	{
		graph = new UndirectedGraph(i_GraphSize);
	}
	return graph;
}


GraphFactory::~GraphFactory()
{
}
