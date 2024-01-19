#include <iostream>
using namespace std;

class Heap{
  public:
  int *arr;
  int capacity;
  int size;

  Heap(int capacity):arr(new int[capacity]),capacity(capacity),size(0){};

  void insert(int val){
    // overflow
    if(size==capacity){
      cout << "Heap is full" <<endl;
      return;
    }
    size++;
    int index=size;
    arr[index]=val;
    while(index>1){
      int parentIndex=index>>1;
      if(arr[index]>arr[parentIndex]){
        swap(arr[index],arr[parentIndex]);
        index=parentIndex;
      }else{
        break;
      }
    }
  }

  int deletefromHeap(){
    int answer=arr[1];
    // repalcement
    arr[1]=arr[size];
    // last elmenet delete kardo
    size--;

    int index=1;

    while(index<size){
      int leftIndex=2*index;
      int rightIndex=2*index+1;

      // curr left and right ma sa max element
      int largest=index;
      if(leftIndex<=size && arr[leftIndex]>arr[largest]){
        largest=leftIndex;
      }
      if(rightIndex<=size && arr[rightIndex]>arr[largest]){
        largest=rightIndex;
      }
      // nochange
      if(largest == index){
        break;
      }else{
        swap(arr[index],arr[largest]);
        index=largest;
      }
    }
    return answer;
  }

  void printHeap(){
    for(int i=1;i<=size;i++){
      cout<<arr[i]<<" ";
    }
  }
};

int main() {
  Heap h(6);
  h.insert(10);
  h.insert(20);
  h.insert(5);
  h.insert(11);
  h.insert(6);
  // h.insert(9);

  h.printHeap();
  cout<<"deleting "<<endl;
  h.deletefromHeap();
  cout<<"after delete "<<endl;
  h.printHeap();

  return 0;
}