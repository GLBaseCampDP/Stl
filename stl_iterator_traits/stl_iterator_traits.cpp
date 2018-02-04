// stl_iterator_traits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//#include <initializer_list>

#include <iostream>
#include <vector>
#include <iterator>
#include <list>
using namespace std;

template<class It>
void reverse_to_conteiner(It first, It last) {
	typename iterator_traits<It>::difference_type n =
		distance(first, last);
	--n;
	typename iterator_traits<It>::value_type tmp;
	while (n > 0) {
		tmp = *first;
		*first++ = *--last;
		*last = tmp;
		n -= 2;
	}
}



void main() {
	cout << " vector - forward ";
	vector<int> vc{ 1, 2, 3, 4 };
	for (auto n : vc)        cout << n << ' ';
	reverse_to_conteiner(vc.begin(), vc.end());
	cout << " reverse: ";
	for (auto n : vc)        cout << n << ' ';

	cout << endl << " list - forward ";
	list<int> ls{ 10, 20, 30, 40, 50 };
	for (auto n : ls)        cout << n << ' ';
	reverse_to_conteiner(ls.begin(), ls.end());
	cout << " reverse: ";
	for (auto n : ls)
		cout << n << ' ';
}


/* 
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
*/