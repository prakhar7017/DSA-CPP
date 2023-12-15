#include <iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseKelement(queue<int>&q,int&k){
  stack<int>st;
  int n=q.size();

  if(k>n || k==0){
    return ;
  }

  for(int i=0;i<k;i++){
    if(!q.empty()){
      int element=q.front();
      q.pop();
      st.push(element);
    }
  }

  while(!st.empty()){
    int element=st.top();
    st.pop();
    q.push(element);
  }

  for(int i=0;i<n-k;i++){
    if(!q.empty()){
      int element=q.front();
      q.pop();
      q.push(element);
    }
  }
}

int main() {
  queue<int>q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);

  int k=3;
  reverseKelement(q,k);

  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }

  return 0;
}