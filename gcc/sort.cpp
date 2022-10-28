#include <ctime>
#include <iostream>

#include <cstdlib>
#include <algorithm>
#include <random>

using namespace std;

double func_time( void( * f )() )
{
    time_t t1 = time( 0 );
    f();
    return time( 0 ) - t1;
}

struct S
{
    int a, b;
};

int a_comp( const void* lhs, const void* rhs )
{
    return ( ( const S* )lhs )->a - ( ( const S* )rhs )->a;
}

int b_comp( const void* lhs, const void* rhs )
{
    return ( ( const S* )lhs )->b - ( ( const S* )rhs )->b;
}

const size_t arr_sz = 50'000'000;
S arr[ arr_sz ];

void fill_arr()
{
    mt19937 gen( 0 );
    uniform_int_distribution< int > distr( -1000000, 1000000 );
    for( S& x : arr )
        x = { distr( gen ), distr( gen ) };
}

void c_sort()
{
    qsort( arr, arr_sz, sizeof( S ), a_comp );
    qsort( arr, arr_sz, sizeof( S ), b_comp );
}

void cpp_sort()
{
    sort( begin( arr ), end( arr ), []( const S& lhs, const S& rhs ){ return lhs.a < rhs.a; } );
    sort( begin( arr ), end( arr ), []( const S& lhs, const S& rhs ){ return lhs.b < rhs.b; } );
}

int sort()
{
    fill_arr();
    cout << "sort: " << func_time( cpp_sort ) << '\n';
    fill_arr();
    cout << "qsort: " << func_time( c_sort ) << '\n';
    return 0;
}
