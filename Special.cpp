#include "Special.h"
#include <iostream>
#include <vector>

using namespace std;

Special::Special(){
   Instance I("x", "x", "x", "x", "x", 2);
   S.push_back(I);
}

Special::~Special(){
}

void Special::SetInstance(Instance d){
   S.erase(S.begin());
   S.push_back(d);
}

void Special::Print(){
   cout << "Special Case: ";
   S[0].Print();
}

Instance Special::GetInstance(){
   return S[0];
}

void Special::Generalize(Instance d){
   if (S[0].type == 0){
      cerr << "Can not Generalize a Positive Instance!" << endl;
      exit(0);
   }
   if (S[0].type == 2){
      SetInstance(d);
   }

   for (int i = 0; i < 5; ++i)
   {
      if (S[0].GetElement(i) != d.GetElement(i)){
         S[0].SetElement("?", i);
      }
   }
}
