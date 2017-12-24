// stl_for_each.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <algorithm> 
#include <iostream> 
#include <vector>
#include <string>
using namespace std; 

template <typename T> void print_element(T el)
{
	cout << el << "; ";
}


int main()
{

	int ar[] = { 5,6,1,56,7,234,7,8,45,65,87 };
	unsigned sz = sizeof(ar) / sizeof(ar[0]);
	vector<string> vec = { "1", "2", "3","Ten" };

	
	cout << "Array: " << endl << "  ";
	for_each(ar, ar + sz, print_element<int>); 
	cout << endl << " Vector: " << endl << "  ";
	for_each(vec.begin(), vec.end(), print_element<string>); 

	int* p = max_element(ar, ar + sz);
	cout << endl <<" array max: " << *p << endl;

	vector<string>::iterator it = max_element(vec.begin(), vec.end());
	cout << " vector max: " << *it << endl;

	
	cout << endl;
	system("pause");
	
	return 0;

    
}

