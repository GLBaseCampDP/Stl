// stl_map.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;
typedef map<int, char*, less<int> > MAP;
#define MIter MAP::iterator
#define PRNElemnts(w)  \
cout << "(" << (*w).first << "," << (*w).second << ") ";

void print(string s, MAP &M) {
	cout << "\n" << s;
	if (M.empty())  cout << "Map is empty"; else
	for (auto&& n : M)   
		cout << "(" << n.first << "," << n.second<<") ";
}
void main() {
	char* NUMBERS[] = { "One", "Two", "Three", "Four", "Five" };
	MAP M1, M2; // ������ ��������
	// ���������� �������� ����� ������� insert �� emplace
	for (int i = 0; i < sizeof(NUMBERS) / sizeof(char*); i++) {
		M1.insert(MAP::value_type(i, NUMBERS[i]));
		M2.emplace(make_pair(i, NUMBERS[i]));
	}
	print(" M1 - ", M1);  print(" M2 - ", M2);
	cout << "\n M1 is reverse form - "; 
	// ���� � ����������� �������
	for (auto i = M1.rbegin(); i != M1.rend(); i++)
		PRNElemnts(i)
		
	// ���� �� ����� ������, ������������ ������ � ������� �'�����
	cout << "\n #size  - M1 : " << M1.size() << ", M2 : " << M2.size()
		<< "\n #max size  - M1 : " << 
		M1.max_size() << ", M2 : "<< M2.max_size() << 
		"\n #count \'5\' - M1 : " << 
		M1.count(5) << ",  M2 : " << M2.count(4);
	// ������ � ��������� ����� � M1
	M1.erase( M1.find(3) ); 
	print(" Delete \'3\' element in M1 - ", M1);
	// ��������� 2 ������� ��������
	M1.erase( M1.find(2), M1.end() ); 
	print(" Delete 2 last element in M1 - ", M1);
	// ������� M1 �� �������� ������� clear()
	M1.clear(); 
	print(" Clear M1 - ", M1);
	cout << "\n";
	cout << "\n";
	system("pause");
}


