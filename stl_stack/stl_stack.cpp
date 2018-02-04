// stl_stack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <algorithm>
#include <initializer_list>
#include <cstring>
#include <functional>
#include <memory>

using namespace std;

int main()
{
	stack< char > v;
	for (unsigned i = 0; i < 3; ++i)
	{
		v.push(char('a' + i));
		cout << " v added: " << char('a' + i) << " ";
	}

	stack< char > v1(v);
	deque< char > s2{ 'a','b','c' };
	stack< char > v2(s2);
	deque< char >&& s3{ 'a','b','c' };
	stack< char > v3(s3);
	stack< char > v4(deque< char >{'a', 'b', 'c'});
	stack< char > v5(deque< char >(initializer_list< char > {'a', 'b', 'c'}));

	char *p = &s2[0];
	*(p + 2) = 't'; // типова помилка
	cout << endl << " v2 top: " << v2.top() <<
		" s[2] = " << s2[2];

	char& p2 = std::ref(v2.top());
	p2 = 'z';
	cout << endl << " v2 top: " << v2.top() << s2[3];

	return 0;
}



