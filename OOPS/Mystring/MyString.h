// Header file for Mystring class

#ifndef MYSTRING_H // if not define
#define MYSTRING_H // then define

#include <iostream>

class MyString{
private:
    char *data; // pointer to char array
    int length; // size of my string

    public :
    // constructor
    MyString();

    // parameterized constructor 
    MyString(const char *str);

    //copy ctor
    MyString(const MyString &other);

    //destructor
    ~MyString();

    int size() const;

    bool empty() const;

    const char *c_str()  const;

    char &operator[](int index);

    int find(const MyString&substr) const;
    // overload insertion operator << for easy output   
    friend std::ostream &operator<<(std::ostream &os, const MyString &str);

 
};
#endif // MYSTRING_H