#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>&st,int& pos,int& ans){
  //base case
  if(pos==1){
    ans=st.top();
    return;
  }

  // 1 case solve
  int temp=st.top();
  st.pop();
  pos--;

  //recursion
  solve(st,pos,ans);

  //backtrack
  st.push(temp);

}

int getMiddle(stack<int>&st){
  int size=st.size();
  if(st.empty()){
    return -1;
  }else{
    int pos=0;
    if(size & 1){ //odd
      pos=(size/2)+1;
    }else{ // even
      pos=size/2;
    }
    int ans=-1;
    solve(st,pos,ans);
    return ans;
  }
}

int main() {

  stack<int>st;

  st.push(10);
  st.push(33);
  st.push(47);
  st.push(25);
  st.push(37);
  st.push(43);

  int mid=getMiddle(st);

  cout<<"Middle is:"<<mid<<endl;


  return 0;
}