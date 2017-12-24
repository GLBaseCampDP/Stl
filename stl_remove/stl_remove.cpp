// stl_remove.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

#define ALL v.begin(), v.end()
#define OUT copy( ALL, ostream_iterator<int>(cout, ", "));
#define OUTALLM(s) cout << "\n " << s;	OUT; cout << "  v.size: " << v.size();

bool pr(int&i) { return i == 1; }

vector<int> v = { -1, 1, -2, -1, 1, 1, 2, 3,-1, 4 };

void vout(vector<int>::iterator pp, char* s) {	cout << s;
	for (auto it = v.begin(); it != v.end(); ++it)	
		cout << *it << ( (it == pp)? "(*)" : "") << ",";
}

int main() {
	OUTALLM("\n v: ")
	auto p2 = remove(ALL, 1);
	vout(p2, "\n\n 2. v(remove: 1): ");
	cout << "\n   v.size: " << v.size() << " *p2: " << *p2 << " index: " << p2 - v.begin() << " last:" << *(v.end() - 1);

	v = { -1, 1, -2, -1, 1, 1, 2, 3,-1, 4 }; 
    p2 = remove_if(ALL, pr);
	v.resize(p2 - v.begin());
	OUTALLM("\n 3. v(resize & remove_if: 1) : ")
	
	v = { -1, 1, -2, -1, 1, 1, 2, 3,-1, 4 }; 
	v.erase(std::remove(ALL, 1), v.end());
	OUTALLM("\n 4. v(erase &remove: 1): ")

	v = { -1, 1, -2, -1, 1, 1, 2, 3,-1, 4 }; 
	cout << "\n\n 5. v(remove_copy: 1): ";	
	std::remove_copy(v.begin(), v.end(),
		std::ostream_iterator<int>(std::cout), 1);
	OUTALLM("   v is preserved: ")
	

	v = { -1, 1, -2, -1, 1, 1, 2, 3,-1, 4 }; 
	cout << "\n\n 6. v(remove_copy_if: 1): ";
	std::remove_copy_if(v.begin(), v.end(),
		std::ostream_iterator<int>(std::cout), [&](int&i) {return i == 1; });
	OUTALLM("   v is preserved: ")

	
	
	cout << "\n\n";

	system("pause");
	return 0;
}
