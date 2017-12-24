// stl_stable_partition.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <deque>  
#include <algorithm>
#include <iterator>

using namespace std;

bool mypred(const int x) {
	return x<51;   //умова на елементи
}

#define COUT(s,v) cout << s; \
 copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", ")); cout << "\n";

int main() {
	setlocale(LC_ALL, "");
	int Arr[] = { 1,78,89,23,51,49,100 };
	deque<int> d(&Arr[0], &Arr[7]);

	COUT(" In deque: ", d);
	stable_partition(d.begin(), d.end(), mypred);
	COUT(" Out deque: ", d);

	cout << "\n";

	system("pause");
	return 0;
}

