// stl_vector_out.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

#define ALL(vv) vv.begin(), vv.end()
#define MESSAGE(s) cout << endl << s

//void S(char i) { cout << i; }

int main() {
	MESSAGE("Vector Output:");
	vector< char> v;                   v.assign(3, 'a');
	for (unsigned i = 0; i < 3; ++i)   v.push_back((int('a') + i + 1));
	for (char i : {'i', 'k', 'l'})     v.push_back(i);

	MESSAGE(" # for & index: ");
	for (unsigned i = 0; i < v.size(); cout << v[i], ++i);

	MESSAGE(" # for & value: ");
	for (char n : v)    // доступ за значенням
		cout << n;

	MESSAGE(" # for & reference: ");
	for (const char& n : v) // доступ за посиланням
		cout << n;

	MESSAGE(" # for & rvalue: "); // доступ за rvalue
	for (auto&& n : v)
		cout << n;

	MESSAGE(" # iterator: ");
	for (vector<char>::iterator it = v.begin(); it != v.end(); ++it)
		cout << *it;

	MESSAGE(" # for_each & data: ");
	for_each(v.data(), v.data() + v.size(), S);

	MESSAGE(" # for_each & iterator: ");
	for_each( ALL(v), S);

	MESSAGE(" # for_each & lambda: ");
	for_each( ALL(v), [](char c) { cout << c; });

	MESSAGE(" # ostream iterator: ");
	copy( ALL(v), ostream_iterator<char>(cout, ""));

	MESSAGE(" # string: "); cout << string(ALL(v)) << endl;

	system("pause");
	return 1;
}

