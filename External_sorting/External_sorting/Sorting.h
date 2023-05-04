#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define vc vector<int>
#define null LONG_MAX
#define srt(a) sort(a.begin(), a.end())

struct specifications {
	int comparisons = 0;
	int assignments = 0;
	int time = 0;
	specifications(int c, int a, int t) { comparisons = c; assignments = a; time = t; };
	specifications() {};
};

class Sorting
{
private:
	static void Merge(vc& b, vc& c, vc& a, int size, int k, int& sizeB, int& sizeC, int& asig, int& comp);
	static void Separation(vc& b, vc& c, vc& a, int size, int k, int& sizeB, int& sizeC, int& asig, int& comp);
	static void FinalMerge(vc& b, vc& c, vc& a, int size, int& asig, int& comp, int& sizeD, int& sizeE);
	static void Separation(vc& b, vc& c, vc& d, vc& e, int k, int n, int& asig, int& comp, int& sizeB, int& sizeC);
	static void FirstSeparation(vc& a, vc& b, vc& c, int n, int& asig, int& comp, int& sizeB, int& sizeC);
	static void MergeNM1f(vc& b, vc& c, vc& a, int size, int& sizeB, int& sizeC, int& asig, int& comp);
	static void SeparationNM1f(vc& b, vc& c, vc& a, int size, int& sizeB, int& sizeC, int& asig, int& comp);
	static void MergeNM2f(vc& b, vc& c, vc& e, vc& d, int size, int& sizeB, int& sizeC, int& sizeE, int& sizeD, int& asig, int& comp);
	static void MergeNM(vc& b, vc& c, vc& e, int& sizeB, int& sizeC, int& indE, int& indB, int& indC, int& asig, int& comp);
	static void Absorging(vc& a, vc&b, int l, int r, int op, int size, int& asig, int& comp);
public:
	static specifications ExternalMergeSort2F(vc& a);
	static specifications ExternalMergeSort1F(vc& a);
	static specifications ExternalNaturalMergingSort1f(vc& a);
	static specifications ExternalNaturalMergingSort2f(vc& a);
	static specifications AbsorbingSort(vc& a);
	static void CreateArray(int Size, vc& A, vc* B = new vc(), vc* C = new vc(), vc* D = new vc(), vc* E = new vc());
	static bool IsSorted(vc& a);

};


