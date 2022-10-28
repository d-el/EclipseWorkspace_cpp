#include <memory>
#include <iostream>
#include <sstream>

class A;

class G
{
public:
    void h(std::shared_ptr<A> a){
        std::cout << "Ep" << std::endl;
        std::cout << a << std::endl;
    }
};

class A: public std::enable_shared_from_this<A>
{
public:
    void f(){
        G g;
        g.h(shared_from_this());
    }
};

int shared_from_this()
{
    std::shared_ptr<A> a = std::make_shared< A >();
    a->f();
    std::cout << a << std::endl;
    return 0;
}
