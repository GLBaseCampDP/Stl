// stl_vector_operation.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

#define END  << endl
#define COUT(v, s) cout END << s; for (char n: v ) cout << n;
#define SZ_CAP  <<st.size()<<" capacity - "<<st.capacity()END;

int main()
{
	using namespace std;
	vector<char> st =
	{ 'H','e','l','l','o',',','w','o','r','l','d' };
	COUT(st, " st: ")
		cout END << " st: size - " SZ_CAP

		vector<char> st_new(st.rbegin(), st.rend());
	COUT(st_new, " st_new reverse build: ")

		st_new.at(0) = 1;
	st_new.front() = 'x';
	COUT(st_new, " st_new first element is changed: ")

		st.resize(st.size() + 1);
	COUT(st, " st resize: ")
		cout END << " st resize (sz+1): size - " SZ_CAP

		st.reserve(2 * st.size());
	cout END << " st reserve (sz): size - " SZ_CAP

		st.shrink_to_fit();
	COUT(st, " st shrink_to_fit: ")
		cout END << " st shrink_to_fit: size - " SZ_CAP

		st_new.erase(st_new.begin(), st_new.begin() + 3);
	COUT(st_new, " st_new erase: ")

		st_new.swap(st);
	COUT(st_new, " st_new swap build: ")

		st_new.resize(4, '-');
	COUT(st_new, " st_new resize (less) with param: ")

		st_new.resize(15, '-');
	COUT(st_new, " st_new resize (great) with param: ")
		return 0;
}
