#include "MyString.h"
#include <cstring> //strcpy, strlen

// definations of functions declared in MyString.h

// MyString header file ka MyString function ki defination
MyString::MyString(){
    data = new char[1];
    length = 0;
    data[0] = '\0';
}

MyString::MyString(const char *str){
    data = new char[strlen(str) + 1];
    length = strlen(str);
    strcpy(data, str); //data copy from str
}

MyString::MyString(const MyString &other){
    data = new char[other.length + 1];
    length = other.length;
    strcpy(data, other.data);
}

MyString::~MyString(){
    delete[] data;
}

int MyString::size() const{
    return length;
}

bool MyString::empty() const{
    return length == 0;
}

const char *MyString::c_str() const{
    return data;
}

// overload insertion operator << for easy output
std::ostream &operator<<(std::ostream &os, const MyString &str){
    os << str.c_str();
    return os;
}

char MyString::operator[](int index){
    if(index>=length){
        return '\0';
    }
    return data[index];
}

int MyString::find(const MyString &substr) const{
    int len = substr.length;
    int i = 0;
    while(i<=length-len){
        int j = 0;
        while(j<len && data[i+j] == substr[j]){
            j++;
        }
        if(j == len){
            return i;
        }
        i++;
    }
    return -1;
}