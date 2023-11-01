#include <iostream>
using namespace std;

void merge(int arr[],int s,int e){

  int mid=s+(e-s)/2;

  //find size of left part
  int lenLeft=mid-s+1;
  // find size of right part
  int lenRight=e-mid;

  // allocate memory to derived size of array
  int *left=new int[lenLeft];
  int *right=new int[lenRight];

  //copy values from orignal array to left array
  int k=s;
  for(int i=0;i<lenLeft;i++){
    left[i]=arr[k++];
  }

  //copy values from orignal array to right array
  k=mid+1;
  for(int i=0;i<lenRight;i++){
    right[i]=arr[k++];
  }

  int leftIndex=0;
  int rightIndex=0;
  //yahi pr galti karte h log
	int mainArrayIndex = s;

  // main merge logic 
  while(leftIndex < lenLeft && rightIndex < lenRight){
    if(left[leftIndex]<right[rightIndex]){
      arr[mainArrayIndex++]=left[leftIndex++];
    }else{
      arr[mainArrayIndex++]=right[rightIndex++];
    }
  }

  while(leftIndex<lenLeft){
    arr[mainArrayIndex++]=left[leftIndex++];
  }
  while(rightIndex<lenRight){
     arr[mainArrayIndex++]=right[rightIndex++];
  }

  // delete the heap memory
  delete[] left;
  delete[] right;
}

void mergeSort(int arr[],int s,int e){
  //base case
  if(s>=e){
    return;
  }
  //processing
  int mid=s+(e-s)/2;

  //recursion->left
  mergeSort(arr,s,mid);

  //recursion->right
  mergeSort(arr,mid+1,e);

  //merge
  merge(arr,s,e);
}

int main() {
  int arr[]={6,5,4,3,2,1};
  int size=6;
  int s=0;
  int e=size-1;
  cout<<"before merge sort: "<<endl;
  for(auto i:arr){
    cout<<i<<" ";
  }
  cout<<endl;
  mergeSort(arr,s,e);
   cout<<"after merge sort: "<<endl;
  for(auto i:arr){
    cout<<i<<" ";
  }
  
  return 0;
}