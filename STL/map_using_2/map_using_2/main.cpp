#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;
typedef map<int, char*, less<int> > MAP;
#define MIter MAP::iterator
#define PRNElemnts(w) cout <<  \
  "(" << (*w).first << "," << (*w).second << ") ";

void print(string s, MAP &M) {
  cout << "\n" << s;
  if (M.empty())  cout << "Map is empty";
  else
    for (auto&& n : M)
      cout << "(" << n.first << "," << n.second<<") ";
}

int main() {
  char* NUMBERS[] =
   { "One", "Two", "Three", "Four", "Five" };
  MAP M1, M2; // Порожні словники
// Заповнюємо  M1 за допомогою insert без дублювання
  for (unsigned i = 0; i < 10; i++) {
if (i < 2)  M1.insert(MAP::value_type(2, "Two"));
if (i < 2 && i < 5) M1.insert(MAP::value_type(7, "Seven"));
if (i > 5) M1.insert(MAP::value_type(10, "Ten"));
}
print(" New created M1 -", M1);
swap(M1, M2); // Перестановка словників
print(" Swap M1 - ", M1);  print(" Swap M2 - ", M2);

cout << "\n M2 range of \'10\' elements -"; // Діапазон 10
for (MIter where = M2.lower_bound(10); where != M2.end();
  where++)
    PRNElemnts(where)

cout << "\n M2 range of \'2\' elements -"; // Діапазон 2
for (MIter where = M2.begin(); where != M2.upper_bound(2);
   where++)
     PRNElemnts(where)

cout << "\n M2 range of \'0\' elements -"; // Діапазон 0
for (MIter where = M2.equal_range(0).first;
  where != M2.equal_range(0).second; where++)
    PRNElemnts(where)

cout << "\n operator [ ] & M2 - "; // використання operator[]
for (MIter where = M2.begin(); where != M2.end(); where++)
  cout << "(" << (*where).first << "," <<
     M2[(*where).first] << ") ";
// Порівняння словників
if (M1 <= M2)   cout << "\n M1 <= M2";
}


