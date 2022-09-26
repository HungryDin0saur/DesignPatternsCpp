#include <iostream>
#include <vector>

//На паттерне Observer основан механизм signal-slots в Qt
//Данный пример иллюстрирует переключение языка в приложении.

enum class Lang
{
    ru, en
};

 //Интерфейст - наблюдатель, от которого наследуются все классы - подписчики на событие о смене языка
class Observer {
public:
    virtual void update(Lang lang) = 0;
};

 //Данный класс отвечает за смену языка в приложении
class Language {
    Lang lang{Lang::ru};
     //В данный вектор заносятся все классы-наблюдатели, которые должны получить сообщение о смене языка.
    std::vector<Observer *> subs;
public:
    void subscribe(Observer *obs) {
        subs.push_back(obs);
    }
     //Выбор языка
    void set_language(Lang lang_) {
        lang = lang_;
        notify();
    }
     //Этот метод уведомляет все классы-наблюдатели о том, что язык в приложении был изменен.
    void notify() {
        for (auto s : subs) {
            s->update(lang);
        }
    }
};

class report_observer : public Observer {
public:
    report_observer(Language *lang) {
        lang->subscribe(this);
    }

    void update(Lang lang) override {
        std::cout << "switch report template to lang " << int(lang) << std::endl;
    }
};

class ui_observer : public Observer {
public:
    ui_observer(Language *lang) {
        lang->subscribe(this);
    }

    void update(Lang lang) override {
        std::cout << "refresh ui for lang " << int(lang) << std::endl;
    }
};

int main(int, char *[]) {
    Language lang;

    report_observer rpt(&lang); //Подписка на событие через ф-ю subscribe(this) внутри конструктора.
    ui_observer ui(&lang); //Подписка на событие через ф-ю subscribe(this) внутри конструктора.

    lang.set_language(Lang::ru); //Вызовет notify(), кторый уведомит все классы-наблюдатели о смене языка

    lang.set_language(Lang::en); //Вызовет notify(), кторый уведомит все классы-наблюдатели о смене языка

    return 0;
}
