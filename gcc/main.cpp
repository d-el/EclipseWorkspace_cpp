#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>
#include <cxxabi.h>

std::string demangle( const char * n )
{
    int st;
    char * dn = abi::__cxa_demangle( n, 0, 0, &st );
    std::string dns = dn ? dn : "???";
    free( dn );
    return dns;
}


int main()
{
    std::vector<int> v;
    std::cout << typeid( v ).name() << '\n';

    std::cout << demangle( typeid( v ).name() ) << '\n';
}
