// Function_Adaptors.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct Less_than_7 : unary_function<int, bool> {
	bool operator()(int i) const { return i < 7; }

};
bool less7(int i) { return i < 7; }

struct VEC {
	int i;
	bool LESS7() { return less7(i); }
	VEC(int j) : i(j) {}
	
};
ostream& operator<< (ostream& s, VEC* v) {
	s << v->i; return s;
}


int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9 };
	cout << " Vector - ";
	copy(v.begin(), v.end(), ostream_iterator<int>(std::cout, " "));
	// ������ ������� �������� � ������� �������
	auto k = bind2nd(greater<int>(), 7);

	// ��������� �������� ������ �� 7
	// ����������� �������� ���������
	cout << "\n Great than 7 (bind2nd) - " <<
		count_if(v.begin(), v.end(), k) << "\n";
	// ��������� �������� ������ ����� �� 7
	// ����������� ����������� �������� ���������
	cout << " Less equal than 7 (not1)- " <<
		count_if(v.begin(), v.end(), not1(k)) << "\n";
	// ��������� �������� ������ �� 7 ����� unary_function
	cout << " Less than 7 (Less_than_7) - " <<
		count_if(v.begin(), v.end(), Less_than_7()) << "\n";
	// ��������� �������� ������ �� 7 ����� ������� �� �������
	cout << " Less than 7 (ptr_fun)  - " <<
		count_if(v.begin(), v.end(), ptr_fun(less7)) << "\n";
	// ��������� �������� ����� ��������-��������� �� ������
	auto k2 = mem_fun_ref(&VEC::LESS7);
	cout << " Less than 7 (Lyambda and mem_fun_ref) - " <<
		count_if(v.begin(), v.end(), [&](VEC kk) {return k2(kk); }) << "\n";

	// ��������� �������� ����� �������� �� ���������
	vector < VEC* > v3 = { new VEC(1),new VEC(2),new VEC(3),new VEC(9) };
	cout << " New vector - ";
	copy(v3.begin(), v3.end(), ostream_iterator<VEC*> (std::cout, " "));

	auto k3 = mem_fun(&VEC::LESS7);
	cout << "\n Less than 7 (mem_fun) - " <<
		count_if(v3.begin(), v3.end(), k3) << "\n";
	
	cout << "\n";
	system("pause");
	return 0;
	
}

