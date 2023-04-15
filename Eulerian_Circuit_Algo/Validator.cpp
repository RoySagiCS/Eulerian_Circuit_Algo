#include "Validator.h"
#include <iostream>
#include <sstream>

Validator::Validator()
{
}

bool Validator::ValidateEdges(int node1, int node2, int n) const
{
	if (node1 < 0 || node1 > n)
	{
		return false;
	}

	if (node2 < 0 || node2 > n)
	{
		return false;
	}
	return true;
}

bool Validator::ValidateNandM(int N, int M)
{
	if (N <= 0 || M <= 0)
	{
		return false;
	}

	//if (!(isANumber(N)) || !(isANumber(M)))
	//{
	//	return false;
	//}

	return true;
}



void Validator::PrintNotValid() const
{
	std::cout << "invalid input";
}

Validator::~Validator()
{
}