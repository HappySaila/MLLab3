#include "Instance.h"
#include <iostream>
#include <vector>

using namespace std;

Instance::Instance(string a, string b, string c, string d , string e, int f){
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		v.push_back(d);
		v.push_back(e);
		type = f;
		isPositive = (type == 1) ? true : false;
}

Instance::~Instance(){
}

void Instance::Print(){
	for (int i = 0; i < 4; ++i)
         {
         	cout << v[i] << ", ";
         }
    cout << v[4] << " <";
    if (type < 2){
	    isPositive ? cout << "True>" : cout << "False>";
    } else {
    	cout << "X>";
    }
    cout << endl;
}

string Instance::GetElement(int i){
	return v[i];
}

bool Instance::isEqual(Instance x){
	for (int i = 0; i < 5; ++i)
	{
		if (v[i] != x.v[i]){
			return false;
		}
	}

	if (type != x.type){
		return false;
	}

	return true;
}

void Instance::SetElement(string t, int n){
	v[n] = t;
}