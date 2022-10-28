#include <iostream>
#include <map>

using namespace std;

class CommandClass {
public:
    CommandClass( std::uint8_t id, std::uint8_t v ): m_id(id), m_version( v ) {};
    virtual ~CommandClass() = default;
    virtual void accept( class Visitor& ) = 0;

    std::uint8_t& get_id() {
        return m_id;
    }

    std::uint8_t& get_version() {
        return m_version;
    }

private:
    std::uint8_t m_id;
    std::uint8_t m_version;
};

//################################################
class Basic : public CommandClass {
public:
    Basic( std::uint8_t v ): CommandClass( 0x03, v ) {};
    void accept( Visitor& ) override;
    void eye() {
        cout << "Red::eye\n";
    }
private:
    std::uint8_t m_val;
};

class SwitchBinary : public CommandClass {
public:
    SwitchBinary( std::uint8_t v ): CommandClass( 0x10, v ) {
    };
    void accept( Visitor& ) override;
    void sky() {
        cout << "Blu::sky\n";
    }
};
//################################################

class Visitor {
public:
    virtual void visit( Basic& ) = 0;
    virtual void visit( SwitchBinary& ) = 0;
};

class CountVisitor : public Visitor {
public:
    CountVisitor() {
        m_num_CC = 0;
    }
    void visit( Basic& ) override
    {
        m_num_CC++;
    }

    void visit( SwitchBinary& ) override
    {
        m_num_CC++;
    }

    void report_num() {
        cout << "CommandClass " << m_num_CC << '\n';
    }
private:
    int m_num_CC;
};

class CallVisitor : public Visitor {
public:
    void visit( Basic &r ) override
    {
        r.eye();
    }
    void visit( SwitchBinary &b ) override
    {
        b.sky();
    }
};

void Basic::accept( Visitor &v ) {
    v.visit( *this );
}

void SwitchBinary::accept( Visitor &v ) {
    v.visit( *this );
}

//################################################

int visitor() {
    CommandClass *cc[] = { new Basic( 1 ), new SwitchBinary( 2 ), 0 };

    CountVisitor count_operation;
    CallVisitor call_operation;

    for( int i = 0; cc[i]; i++ ) {
        cc[i]->accept( count_operation );
        cc[i]->accept( call_operation );

        std::cout << "id " << (int)cc[i]->get_id() << "\n";
        std::cout << "version " << (int)cc[i]->get_version() << "\n";
    }

    count_operation.report_num();
    return 0;
}
