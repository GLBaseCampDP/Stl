#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

#define ALL(v) v.begin(), v.end()
#define OUT(v, s)  cout <<"\n" << s; \
copy( ALL(v), ostream_iterator<int>(cout, ", "));

int main() {
  vector<int> v{ 3, 1, 4, 1, 5, 9 };
  OUT(v, "input v - ");

  make_heap(v.begin(), v.end());
  OUT(v, "make_heap v - ");

  v.push_back(6);
  OUT(v, "push vector v - ");

  push_heap(ALL(v));
  OUT(v, "push heap v - ");

  vector<int> v2{ 3, 1, 4, 1, 5, 9, 6 };
  OUT(v, "input v2 - ");

  make_heap(ALL(v2));
  OUT(v2, "make heap v2 - ");

  sort_heap(ALL(v2));
  OUT(v2, "sort heap v2 - ");

  return 1;
}
