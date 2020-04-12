#include <iostream>
#include <vector>
#include <string>

#define VZ1 &v[sz-1]
#define VZ2 &v[sz-2]
using namespace std;
#define OUT cout <<
#define END  << endl

int main() {
  unsigned sz = 3;
  vector< char> v;   v.assign(sz, 'a');
  for (unsigned i = 0; i < sz; ++i)
   v.push_back((int('a') + i + 1));
  sz = v.size();

  for (char n : v) cout << ' ' << n; OUT"\n";

  char& v_end_m2 = *((char*)long(VZ2));
  char& v_end_m1 = *((char*)long(VZ1));
  char& v_end = *((char*)(long(VZ1) + sizeof(char)));
  char& v_end_p1 =
  *((char*)(long(VZ1) + 2*sizeof(char)));

  OUT" reference - (sz-2) = "<<v_end_m2 << " (sz-1) = "
  << v_end_m1 END<< " - (sz)  = "<< v_end << " (sz+1) = "
  << v_end_p1 END << " adress - (sz-2) = " << hex
  << long(VZ2) << ": (sz-1) = " << long(VZ1) END
  <<" - (sz) = "<< long(VZ1) + sizeof(char)<<" (sz+1) = "
  << long(VZ1) + 2 * sizeof(char) << dec END;

  char* p = v.data() + v.size() ;
  OUT" data pointer - (sz-2) = "<<*(p- 2) << " (sz-1) = "
  << *(p - 1) END << " - (sz)  = " << *p << " (sz+1) = "
  << *(p + 1) END << " adress - (sz-2) = " << hex <<
  long(p - 2)<<" (sz-1) =   "<<long(p - 1) END << " - (sz) = "
  << long(p) << " (sz+1) = " << long(p + 1) << dec END;
}
