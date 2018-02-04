// stl_pair.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

namespace std {
	template <class T1, class T2> struct pair {
		// ���� ������ - ����� ����������  (Key, Value)
		typedef T1 firstType; typedef T2 secondType;
		// ���� �������  
		T1 first; T2 second;
		// ctor �� ����������� - ����������� ������� ����
		pair() : first(T1()), second(T()) {}
		// ���������������� ctor
		pair(const U1& a, const U2& b); constexpr pair(const U1& a, const U2& b);
		// ������� ������������ ���������
		pair(const pair& p) = default;   pair(pair&& p) = default;
		// ���������������� ctor � ������������ ����������� ��� MoveSemantic
		template< class U1, class U2 > pair(U1&& a, U2&& b);
		template< class U1, class U2 > constexpr pair(U1&& x, U2&& y);
		// ctor ��������� � ������������ ������������� 
		template<class U1, class U2> pair(const pair<U1, U2 &p);
		template< class U1, class U2 > constexpr pair(const pair<U1, U2>& p);
		// ctor ��������� � ������������ ������������� ��� MoveSemantic
		template< class U1, class U2 > pair(pair<U1, U2>&& p);
		template< class U1, class U2 > constexpr pair(pair<U1, U2>&& p);
		// ��������� ���������
		pair& operator=(const pair& other);    pair& operator=(pair&& other);
		template< class U1, class U2 > pair& operator=(const pair<U1, U2>& other);
		template< class U1, class U2 > pair& operator=(pair<U1, U2>&& other);
		// ����� ����� ���������� ���
		void swap(pair& other);
	};

}


