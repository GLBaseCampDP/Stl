// stl_copy.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define OUT(v1,v2) copy(v1, v2, ostream_iterator<int>(cout, ", "));

bool pr(int&i) { return i == 0; }

//[&](int&i) {return i > 0; }

int main()
{
	int a[] = { -1, 1, 2, 3, 4 };
	cout << "\n 1. a: " ; OUT(a, a + 5);
	int b[5] = {-100, -101,-102, -103, -104};
	auto f = copy(a, a + 3, b);
	cout << "\n 2. b: "; OUT(b, b+5);
	cout << "\n r = " << *f;
	
	
	vector<int> v = { 0,0,0,0,0 };
	cout << "\n 3. v: "; OUT(v.begin(), v.end());

	copy_if(b, b + 5, v.begin(), [&](int&i) {return i > 0; });
	
	cout << "\n 4. v: "; OUT( v.begin(), v.end() );
	copy_if(v.begin(), v.end(), a, pr);
	cout << "\n 5. a: "; OUT(a, a+5);

	auto g = copy_backward(a, a + 5, v.end());
	cout << "\n 6. v: "; OUT(v.begin(), v.end());
	cout << "\n r = " << *g;


	system("pause");
    return 0;
}

