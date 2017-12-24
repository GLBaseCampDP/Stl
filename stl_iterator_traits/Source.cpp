#include "stdafx.h"

#include <iostream>
#include <vector>
#include <iterator>
#include <list>



using namespace std;

template<class BidirIt>
void reverse_to_conteiner(BidirIt first, BidirIt last)
{
    typename std::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
    --n;
    typename std::iterator_traits<BidirIt>::value_type tmp;
    while(n > 0) {
        tmp = *first;
        *first++ = *--last;
        *last = tmp;
        n -= 2;
    }

}

int main() 
{
	std::cout << endl << " vector - forward ";
	std::vector<int> vc {1, 2, 3, 4};
	for (auto n : vc)
          std::cout << n << ' ';
	reverse_to_conteiner(vc.begin(), vc.end());
	std::cout << " reverse: ";
    for (auto n : vc)
          std::cout << n << ' ';
    std::cout << endl << " list - forward ";
    std::list<int> ls {10, 20, 30, 40, 50};
    for (auto n : ls)
          std::cout << n << ' ';
	reverse_to_conteiner(ls.begin(), ls.end());
	std::cout << " reverse: ";
    for (auto n : ls)
          std::cout << n << ' ';
	return 1;
}