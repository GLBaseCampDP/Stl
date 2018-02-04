// stl_pair.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

namespace std {
	template <class T1, class T2> struct pair {
		// Типи шалону - імена компонентів  (Key, Value)
		typedef T1 firstType; typedef T2 secondType;
		// Поля шаблону  
		T1 first; T2 second;
		// ctor по замовчуванні - ініціалізація базових полів
		pair() : first(T1()), second(T()) {}
		// параметризований ctor
		pair(const U1& a, const U2& b); constexpr pair(const U1& a, const U2& b);
		// дефолтні конструктори копіювання
		pair(const pair& p) = default;   pair(pair&& p) = default;
		// параметризований ctor з автоматичним приведенням для MoveSemantic
		template< class U1, class U2 > pair(U1&& a, U2&& b);
		template< class U1, class U2 > constexpr pair(U1&& x, U2&& y);
		// ctor копіювання з автоматичним перетворенням 
		template<class U1, class U2> pair(const pair<U1, U2 &p);
		template< class U1, class U2 > constexpr pair(const pair<U1, U2>& p);
		// ctor копіювання з автоматичним перетворенням для MoveSemantic
		template< class U1, class U2 > pair(pair<U1, U2>&& p);
		template< class U1, class U2 > constexpr pair(pair<U1, U2>&& p);
		// оператори присвоєння
		pair& operator=(const pair& other);    pair& operator=(pair&& other);
		template< class U1, class U2 > pair& operator=(const pair<U1, U2>& other);
		template< class U1, class U2 > pair& operator=(pair<U1, U2>&& other);
		// метод обміну елементами пар
		void swap(pair& other);
	};

}


