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
        const size_t length();
        const char* getStr();
        bool empty();
        char at(int index);
        void operator = (my_string str2);
        void operator = (const char* str2);
        char operator [] (int index);
        bool operator == (my_string str2);
        my_string operator + (my_string str2); 
    private:
        void setStr(my_string str2);
        void setStr(const char* temp);
        bool equals(my_string str1, my_string str2);
        my_string concat(my_string str1, my_string str2);
        void reset(size_t iniSize);
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
    setStr(temp);
}

const size_t my_string::getSize() {
    return size;
}

const size_t my_string::length() {
    return size;
}

const char* my_string::getStr() {
    return str;
}

bool my_string::empty() {
    return size == 0;
}

void my_string::operator=(my_string str2) {
    setStr(str2);
}

void my_string::operator=(const char* str2) {
    setStr(str2);
} 

bool my_string::operator==(my_string str2) {
    return equals(*this, str2);
}

char my_string::operator[](int index) {
    return at(index);
}

char my_string::at(int index) {
    if(index < 0 || index >= size) throw "Index out of bounds";
    return(*(str+index));
}

my_string my_string::operator +(my_string str2) {
    return concat(*this,str2);
}

int main() {
    my_string s1 = "hey hows it do? im okay myself";
    cout << s1.getStr() << " " << s1.getSize() << "\n"; 
    my_string s2 = "okay nice";
    my_string s3 = s1+s2;
    cout << s3.getStr() << " " << s3.getSize() << "\n";
}

void my_string::setStr(my_string str2) {
    size = str2.getSize();
    reset(size+1);
    const char* temp = str2.getStr();
    for(int i = 0; *temp; i++, temp++) {
        str[i] = *temp;
    }
}

void my_string::setStr(const char* temp) {
    const char* end = temp;
    size_t count = 0;
    while(*end++) count++;
    reset(count+1);
    for(int i = 0; *temp; i++, temp++) {
        str[i] = *temp;
    }
}

bool my_string::equals(my_string str1, my_string str2) {
    if(str1.getSize() != str2.getSize()) return false;
    size_t temp = str1.getSize();
    for(int i = 0; i < temp; i++) {
        if(str1[i] != str2[i]) return false;
    }
    return true;
}

my_string my_string::concat(my_string str1, my_string str2) {
    size_t newSize = str1.length() + str2.length();
    const char* s1 = str1.getStr();
    const char* s2 = str2.getStr();
    int i = 0;
    char* buffer = new char[newSize+1];
    for(i; *s1; i++, s1++) buffer[i] = *s1;
    for(i; *s2; i++, s2++) buffer[i] = *s2;
    my_string newStr(buffer);
    return newStr;
}

void my_string::reset(size_t iniSize) {
    str = new char[iniSize];
    memset(str, 0, iniSize);
    size = iniSize-1;
}


