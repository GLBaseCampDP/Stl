// stl_rotate.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>
#include <vector>

using namespace std;
std::ostream_iterator<int> _out(std::cout, " ");

#define EN << endl ;  
#define COUTS(v0, v1, v2) cout << v0 << "\n  ";\
 std::copy(v1, v2, _out); cout EN



int main()
{
	setlocale(LC_ALL, "Ukrainian");
	
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	unsigned iLen = sizeof(arr) / sizeof(arr[0]);
			
	COUTS(" Input array:", arr, arr + iLen);
	
	cout << " array middle - " << ((iLen - 2) / 2) EN
	
	rotate(arr + 2, arr + ((iLen - 2) / 2), arr + (iLen - 2));
	COUTS(" Rotated array:", arr, arr + iLen);

	vector<int> vec(arr, arr + iLen);
	COUTS(" Input vector:", vec.begin(), vec.end());
	
	cout << " vector middle - " << (vec.size() / 2) EN
	
	rotate(vec.begin() + 2, vec.begin() + (vec.size() / 2), vec.end() - 3);
	COUTS(" Rotated vector:", vec.begin(), vec.end());

	rotate(vec.begin(), vec.begin() + 1, vec.end());
	COUTS(" Forward Cycle shifted vector:", vec.begin(), vec.end());

	rotate(vec.begin(), vec.end() - 1, vec.end());
	COUTS(" Reverse Cycle shifted vector:", vec.begin(), vec.end());

	cout << endl;
	system("pause");
	return 0;
}

