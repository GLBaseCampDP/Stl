#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <ctime>

using namespace std;
vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
#define ALL v.begin(), v.end()
#define EN cout <<"\n";
#define COUT(s,v) cout << s; \
 copy( ALL, ostream_iterator<int>(cout, ", ")); EN

int gen() {
  static int i = 0;
  i++;
  return int(sin(i)*100);
}

struct GEN {
  mt19937 g;
  GEN() : g(static_cast<uint32_t>(time(0))){}
  size_t operator()(size_t n) {
    uniform_int_distribution<size_t> d(0, n ? n - 1 : 0);
    return d(g);
 }
};

int main() {
 COUT(" Input vector: ", v);
 cout << " Itertor To -" <<
  fill_n(v.begin() + 1, 5, -10) - v.begin(); EN
 COUT(" Fill_n example (param 5):\n   ", v);
 generate(ALL, gen);     COUT(" Generate example:\n   ", v);
 fill(ALL, 0);           COUT(" Nulling : ", v);
 int n = { 0 };
 std::generate_n(v.begin(), v.end()- v.begin() - 1,
   [&n] { return int(10*cos(n++)); });
 COUT(" Generate_n example (param 3):\n   ", v);
 random_shuffle( ALL );
 COUT(" Random_shuffle example:\n   ", v);
 random_shuffle( ALL, GEN());
 COUT(" Generator & Random_shuffle example:\n   ", v);
}
