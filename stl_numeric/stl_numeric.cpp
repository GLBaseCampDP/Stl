// stl_heap.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <numeric>

using namespace std;

#define ALL(v) v.begin(), v.end()
#define OUT(v, s)  cout <<"\n" << s; \
copy( ALL(v), ostream_iterator<int>(cout, ", "));

#define OUTM(v, sz, s)  cout <<"\n" << s; \
copy(v, v + sz , ostream_iterator<int>(cout, ", "));


int main()
{
	const int sz = 7;
	int m[sz] = { 1, 3, 4, 5, 7, 8, 9 };
	OUTM(m, sz, "input arr m - ");
	
	list<int> l(m, m+sz);
	list<int> l_res(l.size());

	adjacent_difference(l.begin(), l.end(),
		l_res.begin());
	OUT(l_res, "adjacent_difference list l_res -");
	
	int m_res[sz];
		
	vector< int> v(m, m+sz);
	vector< int> v2(v.size());
    OUT(v, "input vector v - ")
	
	partial_sum(m, m + sz, m_res);
	OUTM(m_res, sz, "partial sum arr m - ");
	
	partial_sum(v.begin(), v.end(), v2.begin());
	OUT(v2, "partial sum vector v2 -");

	cout << "\n\n";
	system("pause");
	return 1;
}
