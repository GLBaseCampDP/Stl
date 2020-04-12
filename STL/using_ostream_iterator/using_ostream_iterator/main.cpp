#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;

int main()
{
    std::string s = "Hello world!\n";
    ofstream of("АA.txt");
    std::copy(s.begin(), s.end(),
        std::ostreambuf_iterator<char>(of));

    ostream_iterator<char> my(cout);
    copy(s.begin(), s.end(), my);

    ostream_iterator<char> my1(cout, " ");
    copy(s.begin(), s.end(), my1);
    *my1++ = '*';*my1++ = '\n';

    list<string> l = {"Hello", " ", "world", "!"};
    ostream_iterator<string> my2(cout, " ");
    copy(l.begin(), l.end(), my2);
    *my2++= "\n";

    std::ostream_iterator<int> i1(std::cout, ", ");
    std::fill_n(i1, 5, -1);

    std::ostream_iterator<double> i2(std::cout);

    *my1++ = '\n';    *i2++ = 3.14;     *my1++ = '\n';
    return 0;
}

