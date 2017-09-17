#ifndef GENERAL_H
#define GENERAL_H
#include <vector>
#include "Instance.h"

class General
{
public:
	General();
	~General();

	void Print();
	void AddHypothesis(Instance d);
	void RemoveHypothesis(Instance d);
	void RemoveInconsistent(Instance x);
	bool isEqual(General G);

	std::vector<Instance> G;
};

#endif