// reference_wrappers.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>  

using namespace std;

std::list<int> l(10);

int main()
{
	for (int& i : l) { 	i = 2; 	}
	
	std::cout << "Contents of the list: ";
	for (int n : l) std::cout << n << ' '; std::cout << '\n';

	std::vector<std::reference_wrapper<int>> v(l.begin(), l.end());
	
	std::cout << "\nContents of the vector: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ""));

	std::for_each(v.begin(), v.end(), [](int &n) { n++; });

	std::cout << "\nContents of the list after change: ";
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, ""));

	std::cout << "\nContents of the vector after change: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ""));
	
	cout << "\n";
	system("pause");
    return 0;
}

