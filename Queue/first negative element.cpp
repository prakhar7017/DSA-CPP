#include <iostream>
#include<deque>
using namespace std;

void firstnegativeElement(int *arr,int &k,int &n){
  deque<int>dq;

  for(int i=0;i<k;i++){
    int element=arr[i];
    if(element<0){
      dq.push_back(i);
    }
  }

  //process remaining window
  for(int i=k;i<n;i++){
    //aage badne sa phle purani window ka answer nikaldo
    if(!dq.empty()){
      cout<<arr[dq.front()]<<" ";
    }else{
      cout<<"0 "<<endl;
    }

    //removal out of range 
    if(i-dq.front()>=k){
      dq.pop_front();
    }

    // addition
    if(arr[i]<0){
      dq.push_back(i);
    }
  }

  // last window ka answer
  if(!dq.empty()){
      cout<<arr[dq.front()]<<" ";
  }else{
      cout<<"0 "<<endl;
  }
}

int main() {
  int arr[]={-2,-5,4,-1,-2,0,5};
  int k=3;
  int n=7;
  firstnegativeElement(arr,k,n);

  return 0;
}