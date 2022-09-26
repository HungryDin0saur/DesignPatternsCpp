#include <iostream>
#include <vector>

class Document { //В данном классе реализована логика работы с файлом
    std::string text;

public:
    void create()
    {
        std::cout << "new document" << std::endl;
        text.clear();
    }

    void new_para(const std::string& para)
    {
        text += para+"\n";
        std::cout << "new para " << para << std::endl;
    }

    void save_as(const std::string& name)
    {
        std::cout << "--- " << name << "---" << std::endl;
        std::cout << text << std::endl;
    }
};

 //Следующие классы являются обертками методов класса Document. Каждый из этих классов вызывает один из методов
 //класса Document. В функциях void py() показаны  примеры автоматической генерации аналогичного кода на python
 //в ходе выполнения программы. Код на python является примером документирования логики выполнения программы.
class Command {
public:
    virtual ~Command() = default;

    virtual void execute() = 0;

    virtual void py() = 0;

protected:
    explicit Command(Document* d)
            :document(d) { }

    Document* document;
};

class NewDocumentCommand : public Command {
public:
    explicit NewDocumentCommand(Document* d)
            :Command(d) { }

    void execute() override
    {
        document->create();
    }

    void py() override
    {
        std::cout << "text = []" << std::endl;
    }
};

class ParaCommand : public Command {
    std::string text;
public:
    ParaCommand(Document* d, std::string text_)
            :Command(d), text(std::move(text_)) { }

    void execute() override
    {
        document->new_para(text);
    }

    void py() override
    {
        std::cout << "text.append(\"" << text << "\")" << std::endl;
    }
};

class SaveAsCommand : public Command {
    std::string fname;
public:
    SaveAsCommand(Document* d, std::string fname_)
            :Command(d), fname(std::move(fname_)) { }

    void execute() override
    {
        document->save_as(fname);
    }

    void py() override
    {
        std::cout << "with open(\"" << fname << """\", \"w\") as f:" << std::endl;
        std::cout << "  f.write(\"\\n\".join(text))" << std::endl;
    }
};

int main(int, char* [])
{
    Document doc;

     //В данном векторе хранятся всевозможные команды, к которым можно обращаться. Данные команды являются
     //оберткой вызовов методов класса Document.
    std::vector<Command*> history;
    history.push_back(new NewDocumentCommand(&doc));
    history.push_back(new ParaCommand(&doc, "Manual"));
    history.push_back(new ParaCommand(&doc, ""));
    history.push_back(new ParaCommand(&doc, "Hello, World!"));
    history.push_back(new SaveAsCommand(&doc, "hello.doc"));

    for (auto i: history) {
        i->execute();
    }

    for (auto i: history) {
        i->py();
    }

    return 0;
}
