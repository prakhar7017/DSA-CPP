#include <iostream>
using namespace std;

class abc{
    int x;
    int *y;
    const int z;

    // to bypass const promise use mutable keyword

    public:
    // abc(int _x,int _y,int _z=0){
    //     x=_x;
    //     y=new int(_y);
    // z=_z;  //ERROR if a member is constant than it will give error while initailazing in constructor
    // }

    // initializing list
    // new way of making constructor
    // (Benefit) if a member is constant than it will not give error while initailazing in constructor Here (n)
    abc(int _x,int _y,int _z=0):x(_x),y(new int(_y)),z(_z){
        cout<<"in init list"<<endl;

    }

    int getx() const { // this function can not modify any member of class
        // x=10; //ERROR , no modification allowed,only read allowed
        return x;
    }
    int setx(int _x){
        x=_x;
    }
    int gety(){
        return *y;
    }
    int sety(int _y){
        *y=_y;
    }
    int getz(){
        return z;
    }
    int setz(int _z){
        // z=_z;
    }

};

void printABC(const abc&a){ 
    // this function can not modify any member of class
    // therefore we have to make all the member function as const
    // cout<<a.getx()<<" "<<a.gety()<<" "<<a.getz()<<endl; //ERROR, gety() and getz() are not const
}

int main()
{
    // const int x=10; // x is a constant
    // initialization can be done
    // but re-assign cannot be done
    // x=20; //ERROR
    // cout<<x<<endl;


    // Const with Pointers 

    // to make DATA_CONSTANT,NON_CONSTANT POINTER: add const before *
    // to make DATA_NON_CONSTANT,CONSTANT POINTER: add const after *
    // to make DATA_CONSTANT,CONSTANT POINTER: add const before and after *

        // const int *a= new int(10);  // Constant data,NON-CONST POINTER
        // int const *a= new int(10);  // same as line 11.
        // cout<<*a<<endl;
        // // *a=20; //ERROR cant change the value of a
        // int b=20;
        // a=&b; // but can change the address of a,pointer itself can be assigned to another address
        // cout<<*a<<endl;

        // CONSTANT POINTER ,NON_CONSTANT DATA
        // int *const a=new int(2);
        // *a=20; // can change the value of a
        // cout<<*a<<endl;
        // int b=10;
        // a=&b; // ERROR cant change the address of a,pointer itself cannot be assigned to another address
        // cout<<*a<<endl;

        // CONSTANT DATA,CONSTANT POINTER
        // const int *const a=new int(2);
        // *a=20; // cant change the value of a
        // cout<<*a<<endl;
        // int b=10;
        // a=&b; // cant change the address of a,pointer itself cannot be assigned to another address
        // cout<<*a<<endl;
}
