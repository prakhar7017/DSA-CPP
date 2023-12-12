#include <iostream>
using namespace std;
class Dqueue{
  int *arr;
  int size;
  int front;
  int rear;
  public :
    Dqueue(int s):arr(new int[s]),size(s),front(-1),rear(-1){};

    void push_back(int data){
      if(rear==size-1){
        cout<<"overflow"<<endl;
        return;
      }else if (front==-1 && rear==-1){
        front++;
        rear++;
        arr[rear]=data;
      }else if(rear==size-1 && front!=0){
        rear=0;
        arr[rear]=data;
      }else{
        rear++;
        arr[rear]=data;
      }
    }
    void push_front(int data){
      if((front==0 && rear==size-1) || rear==front-1){
        cout<<"overflow"<<endl;
        return;
      }else if(front==-1 && rear==-1){
        front++;
        rear++;
        arr[rear]=data;
      }else if( front==0 && rear!=size-1){
        front=size-1;
        arr[front]=data;
      }else{
        front--;
        arr[front]=data;
      }
    }

    void pop_front(){
      if(front==-1 && rear==-1){
        cout<<"underflow"<<endl;
        return;
      }else if(front==rear){
        arr[front]=1;
        front=-1;
        rear=-1;
      }else if(front==size-1){
        arr[front]=1;
        front=0;
      }else {
        arr[front]=-1;
        front++;
      }
    }
    void pop_back(){
      if(front==-1 && rear==-1){
        cout<<"underflow"<<endl;
        return;
      }else if(front==rear){
        arr[rear]=-1;
        front=-1;
        rear=-1;
      }else if(rear==0){
        arr[rear]=-1;
        rear=size-1;
      }else {
        arr[rear]=-1;
        rear--;
      }
    }

     void print(){
      cout<<"Front : "<<front<<endl;
      cout<<"Rear : "<<rear<<endl;
      for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
      }
      cout<<endl;
    }
};

int main() {
  Dqueue dq(5);

  dq.push_back(5);
  dq.print();
  dq.push_front(4);
  dq.print();


  return 0;
}