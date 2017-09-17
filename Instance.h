#ifndef INSTANCE_H
#define INSTANCE_H
#include <vector>

class Instance
{
public:
	Instance(std::string a, std::string b, std::string c, std::string d , std::string e, int f);
	~Instance();

	std::vector<std::string> v;
	int type; //0 = negative 1 = positive 2 = most specific
	bool isPositive;

	void Print();
	std::string GetElement(int i);
	void SetElement(std::string t, int n);
	bool isEqual(Instance x);
};



#endif