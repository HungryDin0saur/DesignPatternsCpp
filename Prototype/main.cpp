#include <iostream>
#include <map>

struct IConnector {
    virtual ~IConnector() = default;

    virtual void connection() = 0;
    virtual IConnector* clone() = 0;
};

class TcpConnector : public IConnector {
    void connection() override
    {
        std::cout << "tcp connection" << std::endl;
    }

    IConnector* clone() override
    {
        return new TcpConnector{};
    }
};

class UdpConnector : public IConnector {
    void connection() override
    {
        std::cout << "udp connection" << std::endl;
    }

    IConnector* clone() override
    {
        return new UdpConnector{};
    }
};

int main(int, char* [])
{
    IConnector* primary = new TcpConnector{};

    std::cout << "primary" << std::endl;
    primary->connection();

     //Такая клнструкция применяется, в том  числе в графических редакторах, когда, например, необходимо
     //скопировать какой-либо элемент. Чтобы скопировать еще и свойства элемента - необходимо использовать
     //копирующий конструктор
    IConnector* mirror = primary->clone();
    std::cout << "mirror" << std::endl;
    mirror->connection();


    delete mirror;

    delete primary;

    return 0;
}
