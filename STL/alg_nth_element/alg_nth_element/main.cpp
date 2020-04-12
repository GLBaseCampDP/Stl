#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define OUT(v, s)  cout <<"\n" << s; copy( ALL(v), \
  ostream_iterator<int>(cout, ", "));
#define POS(v, p)  cout << "\n value - \'" << \
       *(p) << "\' position - " << p - v.begin() << ":";


int main() {
  vector<int> v = { -1, 1, -2, -1, 3, 1, 2, 1,-1, 4 };
  OUT(v,"input: ");
  POS(v, v.begin() + 2);
  nth_element(v.begin(), v.begin() + 2, v.end());
  OUT(v,"ordered: ");

  v = { -1, 1, -2, -1, 1, 1, 2, 3,-1, 4 };
  OUT(v, "input: ");
  POS(v, v.end() - 1);
  nth_element(v.begin(), v.end() - 1, v.end());
  OUT(v, "ordered: ");

  v = { -1, 1, -2, -1, 1, 1, 2, 3,-1, 4 };
  OUT(v, "input: ");
  POS(v, v.begin());
  nth_element(v.begin(), v.begin(), v.end());
  OUT(v, "ordered: ");

  return 0;
}

