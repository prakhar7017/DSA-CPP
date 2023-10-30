// What are Generic Functions in C++?

// Ans: In C++, generic functions refer to functions that are designed to work with a variety of data types, allowing you to write more flexible and reusable code. This is achieved through the use of templates. Templates in C++ enable you to write functions and classes that can operate on different data types while maintaining type safety.

// for exapmle:

#include <iostream>
using namespace std;

template<typename T>
int linearSearch(T arr[], int n,T key){
  for(int i=0;i<n;i++){
    if(arr[i]==key){
      return i;
    }
  }
  return -1;
}

int main() {
  // int arr[]={1,2,3,4,5,6};
  char arr[]={'a','b','c','d','e'};
  int n=sizeof(arr)/sizeof(arr[0]);
  char key='c';
  int ans=linearSearch(arr,n,key);
  cout<<ans<<endl;
  return 0;
}