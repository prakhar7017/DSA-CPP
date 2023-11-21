#include <iostream>
#include <string>
#include "MyString.h"

using namespace std;

int main(){

    MyString s1("prakhar"); // default ctor
    cout << s1 << endl; 
    return 0;
}

// g++ -c MyString.cpp // to create object file of MyString.cpp
// g++ -c main.cpp // to create object file of main.cpp
// g++ -o main main.o MyString.o // to create executable file of main.cpp and MyString.cpp
