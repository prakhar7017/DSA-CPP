#include<iostream>
#include<queue>
using namespace std;

int solve(int *arr,int n,int k){
  if(k>=n){
    return 0;
  }
  priority_queue<int,vector<int>,greater<int>>pq;
  // traverse first k elements
  for(int i=0;i<k;i++){
    pq.push(arr[i]);
  }

  // remaining elemets ko tabhi push karna jab wo chote ho
  for(int i=k;i<n;i++){
    int element=arr[i];
    if(element>pq.top()){
      pq.pop();
      pq.push(element);
    }
  }
  int ans=pq.top();
  return ans;
}
int main(){
  int arr[]={3,7,4,5,8,6,9};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k=41;
  int ans=solve(arr,n,k);
  cout<<endl<<"Kth Largest Element is : "<<ans;
  return 0;
}