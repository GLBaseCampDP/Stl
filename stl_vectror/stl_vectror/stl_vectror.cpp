// stl_vectror.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define VZ1 &v[sz-1]
#define VZ2 &v[sz-2]
#define OUT  cout <<
#define END  <<  endl

void main() {
	unsigned sz = 3;
	 vector< char> v;   v.assign(sz, 'a');
	for (unsigned i = 0; i < sz; ++i)
		v.push_back((int('a') + i + 1));

	sz = v.size();
	 vector<char>::iterator it = v.begin();
	OUT "#access to container any elements  " END
		<< " lvalue by operator[]:  - (sz-2) = "
		<< v[sz - 2] << ": (sz-1) = " << v[sz - 1]  END
		<< " lvalue by at():  - (sz-2) = " << v.at(sz - 2)
		<< ": (sz-1) = " << v.at(sz - 1)  END
		<< " lvalue by iterator:  - (sz-2) = " << *(it + (sz - 2))
		<< ": (sz-1) = " << *(v.end() - 1) END
		<< " use pointers - " << " (sz-2) = " << *(VZ2)
		<< ": (sz-1) = " << *(VZ1) << ": (sz) = "
		<< *(VZ1 + 1) << ": (sz+1) = " << *(VZ1 + 2) END;
	// в новому стандарті це помилка  доступ  
	// cout << v[sz-1] << " " << v[sz] << " " << v[sz+1] <<endl;
	//cout << " -> "<<  *( v.end()  ) << " " << *(v.end() + 1);
	system("pause");
}







