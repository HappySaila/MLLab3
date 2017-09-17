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
	if (g.GetElement(n) != "?" || d.GetElement(n) == g.GetElement(n)){
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


