#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <algorithm>

typedef std::vector<int> VEC;
#define ENDL std::cout <<"\n";

void search(VEC& src, VEC& srch) {
  std::cout << "Source vector: ";
  std::copy(src.begin(), src.end(),
     std::ostream_iterator<int>(std::cout, ", ")); ENDL
  for (auto sr : srch) {
    std::cout << "Searching for " << sr << " -- ";
    (std::binary_search(src.begin(), src.end(), sr)) ?
    std::cout << "Found " : std::cout << "isn't find ";
    ENDL
  }
}

std::vector<int> v{ 1, 3, 4, 5, 9 };
std::vector<int> v1{ 1, 3, 4 };
std::vector<int> unsorted_v{ 9, 7, 4, 1, 2, 3 };

int main() {
   // sorted vectors
   search(v, v1); ENDL
   search(v1, v); ENDL
   // unsorted vectors
   search(unsorted_v, v); ENDL
   return 0;
}
