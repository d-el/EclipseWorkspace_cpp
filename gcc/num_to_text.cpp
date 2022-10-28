#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

string IntLe999toText( int n, int genus, int & cs )
{
    string r;
    if( n / 100 )
    {
        static const string h[] = {
            "сто ", "двести ", "триста ", "четыреста ", "пятьсот ",
            "шестьсот ", "семьсот ", "восемьсот ", "девятьсот "
        };
        cs = 2;
        r += h[ n / 100 - 1 ];
        n %= 100;
    }
    if( n / 10 >= 2 )
    {
        static const string t[] = {
            "двадцать ", "тридцать ", "сорок ", "пятьдесят ",
            "шестьдесят ", "семьдесят ", "восемьдесят ", "девяносто "
        };
        cs = 2;
        r += t[ n / 10 - 2 ];
        n %= 10;
    }
    if( n )
    {
        if( n == 1 )
            cs = 0;
        else if( n < 5 )
            cs = 1;
        else
            cs = 2;
        if( n < 3 )
        {
            static const string ug[][ 2 ] = {
                "oдин ", "одна ", "два ", "две "
            };
            r += ug[ n - 1 ][ genus ];
        }
        else
        {
            static const string u[] = {
                "три ", "четыре ", "пять ", "шесть ", "семь ", "восемь ",
                "девять ", "десять ", "одиннадцать ", "двенадцать ",
                "тринадцать ", "четырнадцать ", "пятнадцать ", "шестнадцать ",
                "семнадцать ", "восемнадцать ", "девятнадцать "
            };
            r += u[ n - 3 ];
        }
    }
    return r;
}

void Order( int & n, string & r, int genus, int order, const string forms[] )
{
    if( n >= order || order == 1 )
    {
        int cs = 2;
        r += IntLe999toText( n / order, genus, cs );
        r += forms[ cs ];
        n %= order;
    }
}

string IntToText( int n, int genus, const string forms[] )
{
    if( n == 0 )
        return "ноль " + forms[ 2 ];
    string r;
    if( n < 0 )
    {
        r += "минус ";
        n = -n;
    }
    static const string bil[] = { "миллиард ", "миллиарда ", "миллиардов " };
    Order( n, r, 0, 1000000000, bil );
    static const string mil[] = { "миллион ", "миллиона ", "миллионов " };
    Order( n, r, 0, 1000000, mil );
    static const string ths[] = { "тысяча ", "тысячи ", "тысяч " };
    Order( n, r, 1, 1000, ths );
    Order( n, r, genus, 1, forms );
    return r;
}

string ansi2oem( const string & s )
{
    char t[] =
        " \xF6\xF7  \x83  \xF0 \xF2    \xF4"
        "  Ii\xA3   \xF1N\xF3    \xF5";
    string r;
    for( size_t i = 0; i < s.size(); ++i )
    {
        unsigned char c = s[ i ];
        if( 0xA0 <= c && c <= 0xBF )
            c = t[ c - 0xA0 ];
        else if( 0xC0 <= c && c <= 0xEF )
            c -= 0x40;
        else if( c >= 0xF0 )
            c-= 0x10;
        r += c;
    }
    //return r;
    return s;
}

class A
{
public:
    int a, b, c, *d;
};

int num_to_text()
{

    vector< int > v( 100, 13 );
    for(auto x: v){
        cout << x << "\n";
    }


    A a;
    cout << a.a << endl;
    cout << a.b << endl;
    cout << a.c << endl;
    cout << a.d << endl;

    return 0;
}
