#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>


int main() {
  std::list<int> l(10);
  for (int& i : l) { i = 2; }

  std::cout << "Contents of the list: ";
  for (int n : l) std::cout << n ; std::cout << '\n';

  std::vector<std::reference_wrapper<int> > v(l.begin(), l.end());
  std::vector<int> v1(l.begin(), l.end());
  // std::vector<int&> v2(l.begin(), l.end()); помилка
  // std::vector< std::ref<int> > v3(l.begin(), l.end());  помилка
  std::cout << "Items of the vector v: ";
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ""));

  std::cout << "\nItems of the vector v1: ";
  std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, ""));

  std::for_each(v.begin(), v.end(), [](int &n) { n++; });

  std::cout << "\nContents of the list: ";
  std::copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, ""));

  std::cout << "\nContents of the vector v: ";
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ""));

  std::cout << "\nContents of the vector v1: ";
  std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, ""));
  std::cout << '\n';
}
