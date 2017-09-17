#include <iostream>
#include <vector>
#include "CEMain.h"

using namespace std;

CEMain::CEMain(){
	G = new General();
	S = new Special();
}

CEMain::~CEMain(){
	delete G;
	delete S;
}

bool CEMain::IsSpecialTerm(Instance g, int n, Instance d){
	if (g.GetElement(n) != "?" || d.GetElement(n) == S->GetInstance().GetElement(n) || S->GetInstance().GetElement(n) == "?"){
		return false;
	}

	return true;
}

string CEMain::GetSpecialTerm(Instance g, int n, Instance d){
	if (!IsSpecialTerm(g, n, d)){
		cerr << "Expected a special term but couldnt find one.";
		exit(0);
	}

	return S->GetInstance().v[n];
}

Instance CEMain::CreateInstance(Instance g, int n, std::string t){
	Instance I(g.GetElement(0), g.GetElement(1), g.GetElement(2), g.GetElement(3), g.GetElement(4), g.type);
	I.v[n] = t;
	return I;
}

bool CEMain::IsConsistentS(Instance d){
	//will return true if d is true under S
	for (int i = 0; i < 5; ++i)
	{
		if (d.GetElement(i)!="?"){
			if (d.GetElement(i) != S->GetInstance().GetElement(i)){
				if (S->GetInstance().GetElement(i)!="?"){
					return false;
				}
			}
		}
	}

	return true;
}



