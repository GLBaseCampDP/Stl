// stl_iterator_traits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
//#include <initializer_list>
using namespace std;
 
template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
    typename std::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
    --n;
	typename std::iterator_traits<BidirIt>::value_type tmp = *first;
	first = last;
	*last = tmp;
    //while(n > 0) {
    //    typename std::iterator_traits<BidirIt>::value_type tmp = *first;
    //    *first++ = *--last;
    //    *last = tmp;
    //    n -= 2;
    //}
}

int _tmain(int argc, _TCHAR* argv[])
{
	initializer_list<int> i1{ 1, 2, 3, 4 };
	std::vector<int> v {1, 2, 3, 4, 5};
    my_reverse(v.begin(), v.end());
    for (int n : v) {
          std::cout << n << ' ';
    }
	system ("pause");
	return 0;
}

