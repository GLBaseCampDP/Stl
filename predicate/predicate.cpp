// predicate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <functional>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define END << endl;

struct __is_odd
{
	bool operator()(const int x) const {
		return (x % 2 == 0);
	}
	bool operator()(const int x, const int y) const {
		return ((x + y) % 2 == 0);
	}
};

bool in(const int& i) {
	return i > 1;
}

template <class T = int >  bool IN(const T& i) {
	return (i >= 1) && (i <= 10);
}

auto fn = [](int i)->bool {return (i % 3 == 0); };



int _tmain(int argc, _TCHAR* argv[])
{
 setlocale(LC_ALL, "Ukrainian");
 int a[] = { 3, 2, 5 };
 vector <int> b = { 1, 1, 5 };
 list <int> c = { 0, 1, 5 };
 // користувацький функтор
 cout << " кiлькiсть непарних елементiв - "
	 << count_if(a, a + sizeof(a) / sizeof(int), __is_odd()) END

 // користувацька функція
 cout << " iндекс елемента бiльшого за 1 - "
	 << distance(b.begin(), find_if( ALL(b), in)) END

 // огортка-посилання
 cout << " iндекс елемента бiльшого за 1 - "
	 << distance(b.begin(), find_if(ALL(b), ref(in))) END
 // обгортка-функція на користувацьку функцію -
 auto k1 = function<bool(int, int)>(__is_odd()); // на бінарнмий предикат
 auto k2 = function<bool(int)>(__is_odd());     // на унарний предикат
 cout << " кiлькiсть парних елементiв - "
	 << count_if(a, a + sizeof(a) / sizeof(int), k2) END
 // користувацька функція-шаблон
 // явна спеціалізація необхідна
 cout << " кiлькiсть елементiв з [1,10] -  "
	 << count_if( ALL(c), IN<int>) END

 cout << " кiлькiсть iз значенням  5 -  " << count_if(
	 ALL(c), [](int i)->bool {return i = 5; } ) END


	system("pause");
    return 1;
}

