// stl_vector_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>

#define VZ1 &v[sz-1]
#define VZ2 &v[sz-2]
using namespace std;
#define OUT cout <<
#define END  << endl


void main() {
	unsigned sz = 3;
	vector< char> v;   v.assign(sz, 'a');
	for (unsigned i = 0; i < sz; ++i)
		v.push_back((int('a') + i + 1));

	char& v_end_m2 = *((char*)int(VZ2));
	char& v_end_m1 = *((char*)int(VZ1));
	char& v_end = *((char*)(int(VZ1) + sizeof(char)));
	char& v_end_p1 = *((char*)(int(VZ1) + 2 * sizeof(char)));

	OUT " reference - (sz-2) = " << v_end_m2 << ": (sz-1) = "
		<< v_end_m1 << ": (sz)  = " << v_end << ": (sz+1) = "
		<< v_end_p1 END << " adress - (sz-2) = " << hex
		<< int(VZ1) << ": (sz-1) = " << int(VZ1)
		<< ": (sz) = " << int(VZ1) + sizeof(char) << ": (sz+1) = "
		<< int(VZ1) + 2 * sizeof(char) << dec END;

	char*p = v.data() + v.size();
	OUT " data pointer - (sz-2) = " << *(p - 2) << ": (sz-1) = "
		<< *(p - 1) << ": (sz)  = " << *p << ": (sz+1) = "
		<< *(p + 1) END << " adress - (sz-2) = " << hex
		<< int(p - 2) << ": (sz-1) =   " << int(p - 1) << ": (sz) = "
		<< int(p) << ": (sz+1) = " << int(p + 1) << dec END;
	system("pause");
}

