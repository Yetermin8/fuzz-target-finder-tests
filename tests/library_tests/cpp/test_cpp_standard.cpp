// 12 Relevant Functions
#include <iostream>
#include <fstream>
#include <future>
#include <cstdlib>

void testCppStandardLibrary() {
    // std::getline
    std::string line;
    std::getline(std::cin, line);

    // ifstream::read, ifstream::getline, ifstream::readsome
    std::ifstream ifs("test.txt");
    if (ifs.is_open()) {
        char buffer[100];
        ifs.read(buffer, 100);
        ifs.getline(buffer, 100);
        ifs.readsome(buffer, 100);
    }

    // istream::read, istream::getline, istream::readsome
    std::istream& is = std::cin;
    char buffer[100];
    is.read(buffer, 100);
    is.getline(buffer, 100);
    is.readsome(buffer, 100);

    // fstream::read, fstream::getline, fstream::readsome
    std::fstream fs("test.txt");
    if (fs.is_open()) {
        fs.read(buffer, 100);
        fs.getline(buffer, 100);
        fs.readsome(buffer, 100);
    }

    // std::async, std::future::get, std::packaged_task
    auto fut = std::async([]{ return 42; });
    std::cout << fut.get() << std::endl;

    std::packaged_task<int()> task([]{ return 42; });
    std::future<int> fut2 = task.get_future();
    task();
    std::cout << fut2.get() << std::endl;

    // std::getenv
    const char* path = std::getenv("PATH");
    std::cout << path << std::endl;
}

int main() {
    testCppStandardLibrary();
    return 0;
}
