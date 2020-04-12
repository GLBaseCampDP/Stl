#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
vector<int> v{ 1,1,1, 3, 3 ,4,4,6,7,7,9,10 };
#define ALL v.begin(), v.end()
#define OUT(s,it) cout << s <<"\n  - Index: " << \
  it - v.begin() << "   Value: " << *it <<"\n";
#define OUT_Pair cout << \
  "\n  - First Index: " <<  p.first - v.begin() << \
  "  Value: " << *p.first << "\n  - Last Index: " << \
  p.second - v.begin() << "  Value: " << *p.second << "\n";

#define IS_EMPTY (p.first == p.second) ? \
  cout << " \n  - range is empty" << endl : OUT_Pair

struct Comparator {
  bool operator() (int& s, int i){return s < i;}
  bool operator() (int i, int& s){return i < s;}
};

bool cmp(const int &a, const int &b) { return a + b < 4; }

int main() {           cout << " In vector: ";
 copy(ALL, ostream_iterator<int>(cout, ", ")); cout << "\n";

 auto it = lower_bound(ALL, 1); OUT(" lower_bound >= 1", it)
 it = lower_bound(ALL, 2);OUT(" lower_bound >= 2", it)
 it = upper_bound(ALL, 4);OUT(" upper_bound > 4", it)
 it = upper_bound(ALL, 5);OUT(" upper_bound > 5", it)
 it = lower_bound(ALL, 2, cmp);
 OUT(" lower_bound (Comp = a + 2 < 4)", it);

 cout << " equal_range = 7";
 auto p = std::equal_range(ALL, 7); IS_EMPTY
 cout << " equal_range = 8";
 p = std::equal_range(ALL, 8);IS_EMPTY
 cout << " equal_range by Comparator = 1";
 p = std::equal_range(ALL, 1, Comparator()); IS_EMPTY
}

