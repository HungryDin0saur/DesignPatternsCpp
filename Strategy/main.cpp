// Стратегия (Strategy)
#include <iostream>

class Generator {
public:
    virtual size_t seed(size_t seed_) = 0;
};

class HardwareGenerator : public Generator {
public:
    size_t seed(size_t) override {
        std::cout << "generate using mac address" << std::endl;
        return 42;
    }
};

class SoftwareGenerator : public Generator {
public:
    size_t seed(size_t) override {
        std::cout << "generate using software emulator" << std::endl;
        return 0;
    }
};

class Shuffle {
public:
    explicit Shuffle(Generator *gen_) : gen(gen_) {}

    size_t seed(size_t seed_) {
        return gen->seed(seed_);
    }

private:
    Generator *gen;
};

int main(int, char *[]) {
     //Здесь мы просто выбираем, какой из генераторов(SoftwareGenerator,HardwareGenerator) будет использован.
     //Класс генератор используется в качестве интерфейса.
    auto p = new Shuffle(new HardwareGenerator);

    p->seed(0);

    return 0;
}
