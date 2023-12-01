#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>&st,int& ele){
  // base case
  if(st.empty()){
    st.push(ele);
    return;
  }

  // 1 case solve
  int temp=st.top();
  st.pop();

  //recursion
  insertAtBottom(st,ele);

  //backtrack
  st.push(temp);
}

void reverStack(stack<int>&st){
  //base case
  if(st.empty()){
    return;
  }

  int temp=st.top();
  st.pop();

  //recursion
  reverStack(st);

  //backtrack
  insertAtBottom(st,temp);
}

int main() {
  stack<int>st;

  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);
  int ele=1000;
  // insertAtBottom(st,ele);

  reverStack(st);
  while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }
  return 0;
}