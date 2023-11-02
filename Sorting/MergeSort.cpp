#include <iostream>
using namespace std;

template<typename T>
void merge(T arr[],int s,int e){
  int mid=s+(e-s)/2;

  int lenLeft=mid-s+1;
  int lenRight=e-mid;

  T *left=new T[lenLeft];
  T *right=new T[lenRight];

  int k=s;
  for(int i=0;i<lenLeft;i++){
    left[i]=arr[k++];
  }
  k=mid+1;
  for(int i=0;i<lenRight;i++){
    right[i]=arr[k++];
  }

  int leftIndex=0;
  int rightIndex=0;
  int mainArrayIndex=s;

  while(leftIndex < lenLeft && rightIndex <lenRight){
    if(left[leftIndex]<right[rightIndex]){
      arr[mainArrayIndex++]=left[leftIndex++];
    }else{
      arr[mainArrayIndex++]=right[rightIndex++];
    }
  }

  while(leftIndex < lenLeft){
    arr[mainArrayIndex++]=left[leftIndex++];
  }

  while(rightIndex <lenRight){
    arr[mainArrayIndex++]=right[rightIndex++];
  }

  delete[] left;
  delete[] right;
}
template<typename T>
void mergeSort(T arr[],int s,int e){
  //base case
  if(s>=e){
    return ;
  }
  //processing
  int mid=s+(e-s)/2;

  //recursive calls
  mergeSort(arr,s,mid);

  mergeSort(arr,mid+1,e);

  merge(arr,s,e);
}

int main(){
  // float arr[]={6.5,5.5,4.5,3.5,2.5,1.5};
  char arr[]={'f','e','d','c','b','a'};
  int size=6;
  int s=0;
  int e=size-1;
  cout<<"before sort"<<endl;
  for(auto it:arr){
    cout<<it<<" ";
  }
  cout<<endl;
  mergeSort(arr,s,e);
   cout<<"after sort"<<endl;
  for(auto it:arr){
    cout<<it<<" ";
  }
  return 0;
}
