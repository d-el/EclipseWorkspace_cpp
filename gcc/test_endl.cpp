#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

const int SIZE = 10000000;

double func_timeen( void( * f )() )
{
    time_t t1 = time( 0 );
    f();
    return time( 0 ) - t1;
}

void f_n()
{
    ofstream f( "f1" );
    for( int i = 0; i < SIZE; ++i )
        f << i << '\n';
}

void f_endl()
{
    ofstream f( "f2" );
    for( int i = 0; i < SIZE; ++i )
        f << i << endl;
}

int test_endl()
{
    cout << " for \\n: " << func_timeen( f_n ) << '\n';
    cout << " for endl: " << func_timeen( f_endl ) << '\n';
    return 0;
}
