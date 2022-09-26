//Flyweight - приспособленец
#include <iostream>
#include <map>

class Image
{
public:
    void resize(int, int) {};
};

 //Данный класс имеет доступ к изображениям одного размера в БД, но разработчику сообщает, что может предоставить
 //изображение любого размера. Перед предоставлением изображения он изменяет его размер. Таким образом данный
 //класс приспосабливается к ситуации.
class ImageResizer
{
    std::map<int, Image> images;
public:
    Image get_box(int w)
    {
        auto i = images.find(w);
        if (i == images.end()) {
            Image img;
            img.resize(w, w);

            bool b;
            std::tie(i, b) = images.emplace(w, img);
        }
        return i->second;
    }
};

int main(int, char *[])
{
    ImageResizer rs;

     //Запрос изоюражения определенного размера
    rs.get_box(100);
    rs.get_box(1000);
    rs.get_box(1000);
}
