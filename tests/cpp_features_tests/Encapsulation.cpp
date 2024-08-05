#include <iostream>
#include <fstream>
#include <string>

class EncapsulatedClass {
public:
    EncapsulatedClass() {
        std::cout << "Constructor called" << std::endl;
    }

    ~EncapsulatedClass() {
        std::cout << "Destructor called" << std::endl;
    }

    void publicMethod() {
        std::ifstream ifs("test.txt");
        if (ifs.is_open()) {
            std::string line;
            std::getline(ifs, line);
            std::cout << line << std::endl;
        }
        protectedMethod();
        privateMethod();
    }

protected:
    void protectedMethod() {
        std::cout << "Protected method called" << std::endl;
    }

private:
    void privateMethod() {
        std::cout << "Private method called" << std::endl;
    }

    int privateMemberVar;
};

void functionUsingEncapsulation() {
    EncapsulatedClass obj;
    obj.publicMethod();
}
