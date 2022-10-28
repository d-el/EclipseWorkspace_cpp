#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>

#define MOVE 0

class Myclass
{
public:
    void txdata( std::vector<std::uint8_t> &data )
    {
        m_txqueue.push( data );
    }

    void txdata( std::vector<std::uint8_t> &&data )
    {
        m_txqueue.push( std::move(data) );
    }

    void view(){
        while( !m_txqueue.empty() )
        {
            const auto& v = m_txqueue.front();
            std::copy( v.begin(), v.end(), std::ostream_iterator< int >( std::cout, " " ) );
            std::cout << '\n';
            m_txqueue.pop();
        }
    }
private:
    std::queue<std::vector<std::uint8_t>> m_txqueue;
};



int main_move(){
    setvbuf( stdout, NULL, _IONBF, 0 );  // Disable stdout buffering
    std::cout << "use move: " << MOVE << std::endl;

    for(int i = 0; i < 3; i++){
        Myclass mc;
        std::vector<std::uint8_t> data0 = {1, 2, 3, 4, 1, 2, 3};
        for(int i = 0; i < 100000000; i++){
            data0.push_back(std::rand());
        }
#if(MOVE > 0)
        mc.txdata( std::move(data0) );
#else
        mc.txdata( data0 );
#endif
        //mc.view();
    }
    return 0;
}
