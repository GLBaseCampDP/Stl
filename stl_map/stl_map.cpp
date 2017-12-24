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
int main() {
	char* NUMBERS[] = { "One", "Two", "Three", "Four", "Five" };
	MAP M1, M2; // ������ ��������
				// ���������� �������� ����� ������� insert �� emplace
	for (int i = 0; i < sizeof(NUMBERS) / sizeof(char*); i++) {
		M1.insert(MAP::value_type(i, NUMBERS[i]));
		M2.emplace(make_pair(i, NUMBERS[i]));
	}
	print(" M1 - ", M1);  print(" M2 - ", M2);
	cout << "\n M1 is reverse form - "; // ���� � ����������� �������
	for (auto i = M1.rbegin(); i != M1.rend(); i++)
		PRNElemnts(i)
		
	// ���� �� ����� ������, ������������ ������ � ������� �'�����
	cout << "\n #size  - M1 : " << M1.size() << ", M2 : " << M2.size()
		<< "\n #max size  - M1 : " << 
		M1.max_size() << ", M2 : "<< M2.max_size() << 
		"\n #count \'5\' - M1 : " << 
		M1.count(5) << ",  M2 : " << M2.count(4);
	M1.erase( M1.find(3) ); // ������ � ��������� ����� � M1
	print(" Delete \'3\' element in M1 - ", M1);
	M1.erase( M1.find(2), M1.end() ); // ��������� 2 ������� ��������
	print(" Delete 2 last element in M1 - ", M1);
	M1.clear(); // ������� M1 �� �������� ������� clear()
	print(" Clear M1 - ", M1);
	// ����������  M1 �� ��������� ������ insert ��� ����������
	for (unsigned i = 0; i < 10; i++) {
		if (i < 2)          M1.insert(MAP::value_type(2, "Two"));
		if (i < 2 && i < 5) M1.insert(MAP::value_type(7, "Seven"));
		if (i > 5)          M1.insert(MAP::value_type(10, "Ten"));
	}
	print(" New created M1 -", M1);
	swap( M1, M2 ); // ������������ ��������
	print(" Swap M1 - ", M1);  print(" Swap M2 - ", M2);
	cout << "\n M2 range of \'10\' elements -"; // ĳ������ 10
	for (MIter where = M2.lower_bound(10); where != M2.end(); where++)
		PRNElemnts(where)
		
	cout << "\n M2 range of \'2\' elements -"; // ĳ������ 2
	for (MIter where = M2.begin(); where != M2.upper_bound(2); where++)
		PRNElemnts(where)
		
	cout << "\n M2 range of \'0\' elements -"; // ĳ������ 0
	for (MIter where = M2.equal_range(0).first;
	     where != M2.equal_range(0).second; where++)
		    PRNElemnts(where)
		
	cout << "\n operator [ ] & M2 - "; // ������������ operator[]
	for (MIter where = M2.begin(); where != M2.end(); where++)
		cout << "(" << (*where).first << "," << M2[(*where).first] << ") ";
	if (M1 <= M2)   cout << "\n M1 <= M2"; // ��������� ��������
	cout << "\n";
	cout << "\n";
	system("pause");
	return 1;
}


