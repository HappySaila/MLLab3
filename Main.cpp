#include <string>
#include <iostream>
#include <vector>
#include "Instance.h"
#include "General.h"
#include "Special.h"
#include "CEMain.h"

using namespace std;
void Test();
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();


int main()
{
	cout << "Candidate Elimination: " << endl;
	Test();
}

void Test(){
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
}

void Test1(){
	//RemoveInconsistent G
	General G;
	Instance I1("1", "?", "?", "?", "?", 1);
	Instance I2("?", "2", "?", "?", "?", 1);
	Instance I3("?", "?", "3", "?", "?", 1);
	Instance I4("?", "?", "?", "4", "?", 1);
	Instance I5("?", "?", "?", "?", "5", 1);
	//remove the initial hypothesis
	G.G.erase(G.G.begin());
	G.AddHypothesis(I1);
	G.AddHypothesis(I2);
	G.AddHypothesis(I3);
	G.AddHypothesis(I4);
	G.AddHypothesis(I5);
	//test1
	Instance x1("1", "2", "3", "5", "4", 1);
	G.RemoveInconsistent(x1);
	General t1;
	t1.G.erase(t1.G.begin());
	t1.AddHypothesis(I1);
	t1.AddHypothesis(I2);
	t1.AddHypothesis(I3);
	if (G.isEqual(t1)){
		cout << "Test 1.1 passed." << endl;
	} else {
		cout << "Test 1.1 failed." << endl;
	}

	//test2
	G.AddHypothesis(I4);
	G.AddHypothesis(I5);
   	Instance x2("?", "?", "?", "?", "?", 1);
	G.RemoveInconsistent(x2);
	General t2;
	t2.G.erase(t2.G.begin());
	if (G.isEqual(t2)){
		cout << "Test 1.2 passed." << endl;
	} else {
		cout << "Test 1.2 failed." << endl;
	}

	//test3
	G.AddHypothesis(I1);
	G.AddHypothesis(I2);
	G.AddHypothesis(I3);
	G.AddHypothesis(I4);
	G.AddHypothesis(I5);
	General t3;
	t3.G.erase(t3.G.begin());
	t3.AddHypothesis(I3);
	t3.AddHypothesis(I5);
   	Instance x3("3", "?", "3", "?", "5", 1);
	G.RemoveInconsistent(x3);
	if (G.isEqual(t3)){
		cout << "Test 1.3 passed." << endl;
	} else {
		cout << "Test 1.3 failed." << endl;
	}
}

void Test2(){
	Special s;

	//test 1
	Instance I("1", "2", "3", "4", "5", 1);
	s.Generalize(I);
	if (s.GetInstance().isEqual(I)){
		cout << "test 2.1 passed." << endl;
	} else {
		cout << "test 2.1 failed." << endl;
	}

	//test 2
	Instance x2("2", "2", "3", "3", "5", 1);
	Instance a2("?", "2", "3", "?", "5", 1);
	s.Generalize(x2);

	if (s.GetInstance().isEqual(a2)){
		cout << "test 2.2 passed." << endl;
	} else {
		cout << "test 2.2 failed." << endl;
	}

	//test 3
	Instance x3("3", "1", "3", "4", "4", 1);
	Instance a3("?", "?", "3", "?", "?", 1);
	s.Generalize(x3);

	if (s.GetInstance().isEqual(a3)){
		cout << "test 2.3 passed." << endl;
	} else {
		cout << "test 2.3 failed." << endl;
	}

	//test 4

	Instance x4("1", "1", "2", "4", "5", 1);
	Instance a4("?", "?", "?", "?", "?", 1);
	s.Generalize(x4);

	if (s.GetInstance().isEqual(a4)){
		cout << "test 2.4 passed." << endl;
	} else {
		cout << "test 2.4 failed." << endl;
	}
}

void Test3(){
	CEMain m;
	//set up S and G
	m.G->G.erase(m.G->G.begin());
	Instance gInit("?", "?", "3", "?", "?", 1);
	Instance sInit("1", "2", "2", "4", "?", 1);
	Instance d("2", "2", "3", "3", "5", 1);
	m.G->AddHypothesis(gInit);
	m.S->Generalize(sInit);

	//test1
	if (m.IsSpecialTerm(m.G->G[0], 0, d) && m.GetSpecialTerm(m.G->G[0], 0, d) == "1"){
		cout << "test 3.1 passed." << endl;
	} else {
		cout << "test 3.1 failed" << endl;
	}

	//test 2
	if (!m.IsSpecialTerm(m.G->G[0], 1, d)){
		cout << "test 3.2 passed." << endl;
	} else {
		cout << "test 3.2 failed" << endl;
	}

	//test 3
	if (!m.IsSpecialTerm(m.G->G[0], 2, d)){
		cout << "test 3.3 passed." << endl;
	} else {
		cout << "test 3.3 failed" << endl;
	}

	//test 4
	if (m.IsSpecialTerm(m.G->G[0], 3, d) && m.GetSpecialTerm(m.G->G[0], 3, d) == "4"){
		cout << "test 3.4 passed." << endl;
	} else {
		cout << "test 3.4 failed" << endl;
	}

	//test 5
	if (!m.IsSpecialTerm(m.G->G[0], 4, d)){
		cout << "test 3.5 passed." << endl;
	} else {
		cout << "test 3.5 failed" << endl;
	}
}

void Test4(){
	//create a specified case from some g given d
	CEMain m;
	Instance gInit("1", "?", "2", "?", "3", 1);

	Instance I = m.CreateInstance(gInit, 1, "6");
	Instance t1("1", "6", "2", "?", "3", 1);
	
	if (t1.isEqual(I)){
		cout << "test 4.1 passed." << endl;
	} else {
		cout << "test 4.1 failed." << endl;
	}

	Instance I2 = m.CreateInstance(I, 3, "6");
	Instance t2("1", "6", "2", "6", "3", 1);
	if (t2.isEqual(I2)){
		cout << "test 4.2 passed." << endl;
	} else {
		cout << "test 4.2 failed." << endl;
	}
}

void Test5(){
	CEMain m;
	Instance s("1", "?", "2", "?", "3", 1);
	m.S->Generalize(s);

	Instance x("?", "?", "?", "?", "?", 1);
	if (m.IsConsistentS(x)){
		cout << "test 5.1 passed." << endl;
	} else {
		cout << "test 5.1 failed" << endl;
	}

	Instance x2("1", "?", "2", "?", "3", 1);
	if (m.IsConsistentS(x2)){
		cout << "test 5.2 passed." << endl;
	} else {
		cout << "test 5.2 failed" << endl;
	}

	Instance x3("1", "?", "3", "?", "3", 1);
	if (!m.IsConsistentS(x3)){
		cout << "test 5.3 passed." << endl;
	} else {
		cout << "test 5.3 failed" << endl;
	}

	Instance x4("?", "2", "2", "2", "3", 1);
	if (m.IsConsistentS(x4)){
		cout << "test 5.4 passed." << endl;
	} else {
		cout << "test 5.4 failed" << endl;
	}

}









