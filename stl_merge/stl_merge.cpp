// stl_merge.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define OUT(v, s)  cout <<"\n" << s; \
copy( ALL(v), ostream_iterator<int>(cout, ", "));

typedef vector<int> VINT;

VINT v = { 1, 6, 9, 3, 4, 5, 6 },
     v1 = { 1, 1, 3, 3, 4, 5, 6 },
     v2 = { 4, 5, 6, 6, 7, 7, 8, 9 };


int main()
{
	OUT(v, "input: ");
	inplace_merge(v.begin(), v.begin()+3, v.end());
	OUT(v, "inplace_merge - output: ");
	v.clear();
	OUT(v1, "input 1: ");
	OUT(v2, "input 2: ");

	set_symmetric_difference(ALL(v1), ALL(v2), std::back_inserter(v));
	OUT(v, "set_symmetric_difference - output: ");

	cout << "\n\n";

	system("pause");
	return 0;
}


