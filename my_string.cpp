#include <cstddef>
#include <iostream>
#include <cstring>

using namespace std;

#define INITIAL_SIZE 15

class my_string{
    private:
        char* str;
        size_t size;
    public:
        my_string();
        my_string(size_t iniSize);
        my_string(const char* temp);
        const size_t getSize();
        const char* getStr();
};

my_string::my_string() {
    str = new char[INITIAL_SIZE];
    memset(str, 0, INITIAL_SIZE);
    size = INITIAL_SIZE;
}

my_string::my_string(size_t iniSize) {
    str = new char[iniSize];
    memset(str, 0, iniSize);
    size = iniSize;
}

my_string::my_string(const char* temp) {
    //check every char after until we reach null value meaning string is ended
    const char* end = temp;
    while(*end++ != 0);
    size_t newSize = end - temp - 1; 

    str = new char[newSize];
    size = newSize;
    for(int i = 0; *temp; i++, temp++) {
        str[i] = *temp;
    }
}

const size_t my_string::getSize() {
    return size;
}

const char* my_string::getStr() {
    return str;
}

int main() {
    my_string s1("hey hows it do? im okay myself");
    cout << s1.getStr() << " " << s1.getSize() << "\n";
}



