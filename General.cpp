#include "General.h"
#include <iostream>
#include <vector>

using namespace std;

General::General(){
   string s[5] = {};
   Instance I("?", "?", "?", "?", "?", 1);
   G.push_back(I);
}

General::~General(){
}

void General::Print(){
   for (int i = 0; i < G.size(); ++i)
   {
      G[i].Print();
   }
}

void General::AddHypothesis(Instance d){
   G.push_back(d);
   //remove some hypothesis in G that is more general than d.
}

void General::RemoveInconsistent(Instance x){
   //any element in G that is more specific than x must be removed
   vector<Instance> newHypothesis;
   for (auto & g : G)
   {
      // for every hypothesis g in G
      bool canAdd = true;
      for (int j = 0; j < 5; ++j)
      {
         //for every element in g
         if (g.GetElement(j) != "?" && g.GetElement(j)!=x.GetElement(j)){
            canAdd = false;
            break;
         }
      }

      if (canAdd){
         newHypothesis.push_back(g);
      }
   }

   G.clear();
   for (int i = 0; i < newHypothesis.size(); ++i)
   {
      G.push_back(newHypothesis[i]);
   }
}

bool General::isEqual(General g){
   if (g.G.size() != G.size()){
      return false;
   }

   for (int i = 0; i < G.size(); ++i)
   {
      for (int j = 0; j < 5; ++j)
      {
         if (g.G[i].GetElement(j) != G[i].GetElement(j)){
            return false;
         }
      }
   }
   return true;
}


