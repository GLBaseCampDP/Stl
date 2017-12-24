// stl_iterator_tag.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"





#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <iterator>
using namespace std;

#define ITER_CALL template< class iter > void iter_call(iter,iter,  

ITER_CALL std::bidirectional_iterator_tag)
{
    std::cout << "Bidirectional iterator is used\n";
}
 
ITER_CALL  std::random_access_iterator_tag)
{
    std::cout << "Random-access iterator is used\n";
}

ITER_CALL   std::forward_iterator_tag)
{
    std::cout << "Forward iterator is used\n";
}


template< class Iter >
void iter_call(Iter first, Iter last)
{
    iter_call(first, last,
        typename std::iterator_traits<Iter>::iterator_category());
}
 

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<int> v;
    iter_call(v.begin(), v.end());
 
    std::list<int> l;
    iter_call(l.begin(), l.end());

	std::forward_list<int> q;
    iter_call(q.begin(), q.end());
 
	system ("pause");
	return 0;
}

