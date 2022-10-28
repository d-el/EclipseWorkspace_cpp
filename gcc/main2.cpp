#include <functional>
#include <iostream>

using fnPointer = void(*)();

// сишная  которая принимает указатель на коллбек
void callbackExecutor( void* fn ) {
    auto casted_fn = reinterpret_cast< fnPointer >( fn );
    casted_fn();
}

template< int a >
struct staticVrapper {
    // переменная которую будем менять
    static std::function< void() > fn;
    // сам статический коллбек
    static void statCallback() {
        fn();
    }
    ;

};

//определение тк статическая переменная должна где нибудь храниться
template< int a >
std::function< void() > staticVrapper< a >::fn;

int main2() {
    // динамически заполняем статически аллоцированный колбек
    staticVrapper< 1 >::fn = []() { std::cout<<"asd"; };

    callbackExecutor( (void*)( &staticVrapper< 1 >::statCallback ) );
    return 0;
}
