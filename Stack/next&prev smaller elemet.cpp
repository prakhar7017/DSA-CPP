#include <iostream>
#include <stack>
#include <vector>
using namespace std;


void prevSmallerElement(vector<int>&arr,vector<int>&ans){
  stack<int>st;
  st.push(-1); // edge case for last element

  for(int i=0;i<arr.size();i++){
    int curr=arr[i];
    while(!st.empty() && st.top()>=curr){
      st.pop();
    }
    ans[i]=st.top();

    st.push(curr);
  }
}
void nextSmallerElement(vector<int>&arr,vector<int>&ans){
  stack<int>st;
  st.push(-1); // edge case for last element

  for(int i=arr.size()-1;i>=0;i--){
    int curr=arr[i];
    while(!st.empty() && st.top()>=curr){
      st.pop();
    }
    ans[i]=st.top();

    st.push(curr);
  }
}

int main() {
  vector<int>arr={8,4,6,2,3};
  vector<int>ans(5);
  prevSmallerElement(arr,ans);
  for(auto it:ans){
    cout<<it<<" ";
  }
  return 0;
}

