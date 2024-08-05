#include <iostream>
#include <fstream>
#include <string>

class MyClass {
public:
    void method1() {
        std::ifstream ifs("test.txt");
        if (ifs.is_open()) {
            std::string line;
            std::getline(ifs, line);
            std::cout << line << std::endl;
        }
        method2();
    }

    void method2() {
        std::cout << "Method2 called" << std::endl;
    }

private:
    int memberVar;
};

void functionUsingClass() {
    MyClass obj;
    obj.method1();
}
