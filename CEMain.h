#ifndef CEMAIN_H
#define CEMAIN_H
#include <vector>
#include "General.h"
#include "Special.h"

class CEMain
{
public:
	CEMain();
	~CEMain();

	General* G;
	Special* S;

	bool IsSpecialTerm(Instance g, int n, Instance d);
	std::string GetSpecialTerm(Instance g, int n, Instance d);
};

#endif