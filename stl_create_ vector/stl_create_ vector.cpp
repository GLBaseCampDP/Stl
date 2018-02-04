// stl_create_ vector.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>

using namespace std;

auto STR = [](string s, string s1 = " (by string)") ->\
string{ return s + string(" container output") + \
s1 + string(": "); };

#define END  << endl           
#define str(v) << string(v.begin(), v.end()) END ;
#define OUT(v) cout << STR(#v) str(v);

int main() {

	vector< char> v;
	v.assign(3, 'a');
	for (unsigned i = 0; i < 3; ++i)
		v.push_back((int('a') + i + 1));

	for (char i : {'i', 'k', 'l'})
		v.push_back(i);
	
	vector< char> v1 = v;                       OUT(v1)

	vector< char> v2(3);                       OUT(v2)

	vector< char> v3(v.begin(), v.end() - 3);   OUT(v3)

	initializer_list<char> l = { 'l','l' };
	vector< char> v4 = l;                      OUT(v4)

	// vector< char> v5(3) = {'a','a','a'} ;   помилка
	vector< char> v5 = { 'a','a','a' };          OUT(v5)

	vector< char> v6;
	v6.insert(v6.end(), l.begin(), l.end());    OUT(v6)

	auto al = { 'a', 'b', 'c' };
	vector< char> v7(al);                     OUT(v7)

	vector< char> v8(3, 'a');                   OUT(v8)
}


