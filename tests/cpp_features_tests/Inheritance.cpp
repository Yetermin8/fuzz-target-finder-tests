#include <iostream>
#include <fstream>
#include <string>

class BaseClass {
public:
    virtual void virtualMethod() {
        std::cout << "BaseClass virtualMethod" << std::endl;
    }
    void nonVirtualMethod() {
        std::cout << "BaseClass nonVirtualMethod" << std::endl;
    }
};

class DerivedClass : public BaseClass {
public:
    void virtualMethod() override {
        std::ifstream ifs("test.txt");
        if (ifs.is_open()) {
            std::string line;
            std::getline(ifs, line);
            std::cout << line << std::endl;
        }
        std::cout << "DerivedClass virtualMethod" << std::endl;
    }
};

void polymorphicFunction(BaseClass* base) {
    base->virtualMethod();
}

void functionUsingInheritance() {
    DerivedClass derivedObj;
    polymorphicFunction(&derivedObj);
}
