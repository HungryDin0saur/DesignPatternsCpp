#include <iostream>

class Singleton
{
public:
    //Метод instance необходим для хранения единственного экзенмпляра статического класса
    //s должен быть возвращен по ссылке, чтобы не произошло копирования
    static Singleton& instance(int b)
    {
        static Singleton s;
        //data_ = b;
        return s;
    }

    static int data_;

    //int& data() { return data_; }

private:
    //Объявили конструктор, конструктор копирования и оператор присваивания,
    //так как они не должны использоваться в статических классах
    Singleton() {}

    Singleton(Singleton const&) {}
    Singleton& operator= (Singleton const&) {}
};

int main()
{
    //Первое обращение
    Singleton& s = Singleton::instance(0);

    //int d = s.data();
    //std::cout << std::endl << d << std::endl;

    Singleton::instance(5);

    //d = s.data();
    //std::cout << std::endl << d;

    return 0;
}
