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

void insertSorted(stack<int>& st,int ele){
    //base case
    if(st.empty() || ele>st.top()){
        st.push(ele);
        return;
    }

    // 1case 
    int temp=st.top();
    st.pop();

    //recursion
    insertSorted(st,ele);

    //backtrack
    st.push(temp);
}

void sortStack(stack<int>&st){
  // base casre
  if(st.empty()){
    return;
  }

  // 1 case
  int temp=st.top();
  st.pop();

  //recursion
  sortStack(st);

  //backtrack
  insertSorted(st,temp);
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

  sortStack(st);

  reverStack(st);
  while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }
  return 0;
}