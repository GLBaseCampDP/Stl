// stl_map.cpp: определяет точку входа для консольного приложения.
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
	MAP M1, M2; // Порожні словники
				// Заповнення словника через функції insert та emplace
	for (int i = 0; i < sizeof(NUMBERS) / sizeof(char*); i++) {
		M1.insert(MAP::value_type(i, NUMBERS[i]));
		M2.emplace(make_pair(i, NUMBERS[i]));
	}
	print(" M1 - ", M1);  print(" M2 - ", M2);
	cout << "\n M1 is reverse form - "; // Вивід у зворотньому порядку
	for (auto i = M1.rbegin(); i != M1.rend(); i++)
		PRNElemnts(i)
		
	// Вивід на екран розмірів, максимальних розмірів і кількості п'ятірок
	cout << "\n #size  - M1 : " << M1.size() << ", M2 : " << M2.size()
		<< "\n #max size  - M1 : " << 
		M1.max_size() << ", M2 : "<< M2.max_size() << 
		"\n #count \'5\' - M1 : " << 
		M1.count(5) << ",  M2 : " << M2.count(4);
	M1.erase( M1.find(3) ); // Шукаємо і видаляємо трійку в M1
	print(" Delete \'3\' element in M1 - ", M1);
	M1.erase( M1.find(2), M1.end() ); // Видалення 2 останніх елементів
	print(" Delete 2 last element in M1 - ", M1);
	M1.clear(); // Очищаємо M1 за допомого функції clear()
	print(" Clear M1 - ", M1);
	// Заповнюємо  M1 за допомогою методу insert без дублювання
	for (unsigned i = 0; i < 10; i++) {
		if (i < 2)          M1.insert(MAP::value_type(2, "Two"));
		if (i < 2 && i < 5) M1.insert(MAP::value_type(7, "Seven"));
		if (i > 5)          M1.insert(MAP::value_type(10, "Ten"));
	}
	print(" New created M1 -", M1);
	swap( M1, M2 ); // Перестановка словників
	print(" Swap M1 - ", M1);  print(" Swap M2 - ", M2);
	cout << "\n M2 range of \'10\' elements -"; // Діапазон 10
	for (MIter where = M2.lower_bound(10); where != M2.end(); where++)
		PRNElemnts(where)
		
	cout << "\n M2 range of \'2\' elements -"; // Діапазон 2
	for (MIter where = M2.begin(); where != M2.upper_bound(2); where++)
		PRNElemnts(where)
		
	cout << "\n M2 range of \'0\' elements -"; // Діапазон 0
	for (MIter where = M2.equal_range(0).first;
	     where != M2.equal_range(0).second; where++)
		    PRNElemnts(where)
		
	cout << "\n operator [ ] & M2 - "; // використання operator[]
	for (MIter where = M2.begin(); where != M2.end(); where++)
		cout << "(" << (*where).first << "," << M2[(*where).first] << ") ";
	if (M1 <= M2)   cout << "\n M1 <= M2"; // Порівняння словників
	cout << "\n";
	cout << "\n";
	system("pause");
	return 1;
}


