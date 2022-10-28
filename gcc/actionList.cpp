#include "iostream"
#include "vector"
#include "functional"

int actlist(){
    std::vector< std::function< void() > > actionList;
    int i = 13;
    actionList.push_back( [](){ std::cout << "Yes, it is\n"; } );
    actionList.push_back( [i](){ std::cout << "Caramba!!! i = " << i << "!!!\n"; } );
    i = 42;
    for( auto& x : actionList )
        x();
    return 0;
}


