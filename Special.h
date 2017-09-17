#ifndef SPECIAL_H
#define SPECIAL_H
#include <vector>
#include "Instance.h"

class Special
{
public:
	Special();
	~Special();

	void Print();
	Instance GetInstance();
	void SetInstance(Instance d);
	void Generalize(Instance d);

private:
	std::vector<Instance> S;
};

#endif