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
    int a = 0;
    const char* t = temp;
    while(*temp++) {
        a++;
    }
    str = new char[a];
    int b = 0;
    for(b;*t;t++,b++) {
        str[b] = *t; 
    }
    size = b;
}

const size_t my_string::getSize() {
    return size;
}

const char* my_string::getStr() {
    return str;
}

int main() {
    my_string temp(20);
    const char* a = temp.getStr();
    size_t s = temp.getSize();
    char newArr[s];
    for(int i = 0; i < s; i++) {
        newArr[i] = *(a+i);
    }
    cout << a << "\n";
    for(int i = 0; i < s; i++) {
        cout << newArr[i];
    }
}



