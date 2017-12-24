// stl_vectror.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>

#define VZ_1 &v[sz-1]
#define VZ_2 &v[sz-2]
#define S  std::
#define OUT S cout <<
#define END  << S endl
#define OUTE S cout END







int _tmain(int argc, _TCHAR* argv[])
{
	unsigned sz = 3;
    S vector< char> v;
    v.assign(sz,'a');
	for (unsigned i = 0; i < sz; ++i)
         v.push_back( (int('a')+ i+1) );
	
	OUT "#container creation and output  " END;
	OUT " v container output (by for): ";
    for (char n : v) 
        OUT n ;

    // різні спосби побудови стрінга з вектора
	// string ss(v.begin(),v.end()); 
	// ss.assign(v.begin(),v.end()); cout << ss <<endl;
	OUTE <<" v container output (by string): "
	    << S string(v.begin(), v.end()) END ;

	S vector< char> v1 = v;
	OUT " v1 container output (by string): "
	    << S string(v1.begin(), v1.end()) END ;
	

	OUTE;
	
	sz = v.size();
	S vector<char>::iterator it = v.begin();
	OUT "#access to container any elements  " END
	  << " lvalue by operator[]:  - (sz-2) = " << v[sz-2] << ": (sz-1) = " << v[sz-1]  END
	  << " lvalue by at():  - (sz-2) = " << v.at(sz-2) << ": (sz-1) = " << v.at(sz-1)  END
	  << " lvalue by iterator:  - (sz-2) = " << *(it+(sz-2)) << ": (sz-1) = " << *(v.end() - 1) END
	  << " use pointers - " << " (sz-2) = " <<  *(VZ_2) << ": (sz-1) = " <<  *(VZ_1) << ": (sz) = " <<  *(VZ_1 + 1) << ": (sz+1) = " << *(VZ_1 +2) END;
	// в новому стандарті це помилка  доступ  
	// cout << v[sz-1] << " " << v[sz] << " " << v[sz+1] <<endl;
	//cout << " -> "<<  *( v.end()  ) << " " << *(v.end() + 1) <<endl;
	
	char& v_end_m2 = *((char*)int(VZ_2));
	char& v_end_m1 = *((char*)int(VZ_1)) ;
	char& v_end = *((char*)(int(VZ_1) + sizeof(char)));
	char& v_end_p1 = *((char*)(int(VZ_1) + 2*sizeof(char)));
	OUT " reference - (sz-2) = " << v_end_m2 << ": (sz-1) = " << v_end_m1 << ": (sz)  = " << v_end << ": (sz+1) = " << v_end_p1 END
		<< " adress - (sz-2) = " << S hex << int(VZ_2)<< ": (sz-1) = " << int(VZ_1) << ": (sz) = " << int(VZ_1) + sizeof(char) << ": (sz+1) = " << int(VZ_1) + 2*sizeof(char) << S dec END;

	char*p = v.data() + v.size();
	OUT " data pointer - (sz-2) = " <<*(p-2) << ": (sz-1) = " << *(p-1)  << ": (sz)  = " << *p << ": (sz+1) = " << *(p+1) END
	<< " adress - (sz-2) = " << S hex << int(p-2)<< ": (sz-1) = " << int(p-1) << ": (sz) = " << int(p) << ": (sz+1) = " << int(p+1) << S dec END;

	
	OUTE;

	S iterator_traits<S vector< char>::iterator>::difference_type n = S distance(v.begin(), v.end());
	OUT "#container size  " END <<" container size capacity & max size: " 	      
      << v.size() << " " << v.capacity() << " " << v.max_size() END
      <<" container size (by adress()): "  <<  int(&v[sz-1] - &v[0]) + 1 END
	  <<" container size (by iterator()): " <<  v.end() - v.begin() END
	  <<" container size (by distance()): " <<  n END;
	
	OUTE;

	v.reserve(2*sz);
    OUT "#container reserve  " END <<" container size capacity & max size: " 	      
    << v.size() << " " << v.capacity() << " " << v.max_size() END;
	
	
	
	  
	
	system ("pause");
	
	return 0;
}







