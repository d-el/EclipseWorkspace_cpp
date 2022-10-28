#include <iostream>
#include <string>
#include <functional>

using namespace std;

// c-like-library

void ( *callback )(int) = nullptr;

void c_like_function( void ( *f )(int) )
{
    callback = f;
}

void c_process()
{
    if( callback )
        callback(15);
    else
        cout << "callback is nullptr\n";
}

int ( *callback2 )(int) = nullptr;

void c_like_function2( int ( *f )(int) )
{
    callback2 = f;
}

void c_process2()
{
    if( callback2 ){
        int i = callback2(16);
        (void)i;
    }
    else
        cout << "callback is nullptr\n";
}

// cpp-like interface

class CppClass
{
public:
    CppClass( const string& str ): str_( str ){}
    void method(int i) { cout << i << ": method for \"" << str_ << "\"\n"; }
    int method2(int i) { cout << i << ": method2 for \"" << str_ << "\"\n"; return 10; }

private:
    string str_;
};

// wrapping

template< typename T, typename F, T* obj, F T::*member >
struct Wrapper;

template< typename T, typename R, typename... Args, T* obj, R ( T::* member )( Args... ) >
struct Wrapper< T, R( Args... ), obj, member >
{
    static R f( Args... args )
    {
        //invoke( member, obj, args... );
        return ( obj->*member )( args... );
    }
};

// test
CppClass foo( "foo" );

int membercallback()
{



    c_like_function( Wrapper< CppClass, void(int), &foo, &CppClass::method >::f );
    c_process();

    c_like_function2( Wrapper< CppClass, int(int), &foo, &CppClass::method2 >::f );
    c_process2();
    return 0;
}
