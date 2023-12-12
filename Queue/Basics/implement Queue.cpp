#include <iostream>
using namespace std;

class Queue{
  int* arr;
  int size;
  int front;
  int rear;

  public:
    Queue(int s):size(s),arr(new int[s]),front(-1),rear(-1){};

    void push(int data){
      // overflow
      if(rear==size-1){
        cout<<"Overflow "<<endl;
        return; 
      }else if(front==-1 && rear==-1){ // first element
        rear++;
        front++;
        arr[rear]=data;
      }else{ // noraml case
        rear++;
        arr[rear]=data;
      }
    }

    void pop(){
      // underflow
      if(front==-1 && rear==-1){
        cout<<"underflow"<<endl;
        return;
      }else if(front==rear){ //single element
        arr[front]=-1;
        front=-1;
        rear=-1;
      }else{ // normal pop
        arr[front]=-1;
        front++;
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

    int getSize(){
        if(front==-1 && rear==-1){
            return 0;
        }
        return rear-front+1;
    }

    int getFront(){
      if(front==-1){
        cout<<"underflow"<<endl;
        return -1;
      }
      return arr[front];
    }

    bool isEmpyt(){
      if(front==-1 && rear==-1){
        return true;
      }
      else {
        return false;
      }
    }

};

int main() {
  Queue q(5);
  q.push(10);
  q.print();
    q.push(20);
  q.print();
    q.push(30);
  q.print();
    q.push(40);
  q.print();
    q.push(50);
  q.print();
    q.push(60);
  q.print();

  cout<<"front is "<<q.getFront()<<endl;

  q.pop();
  q.print();

  q.push(60);
  q.print();

  q.pop();
  q.pop();
  cout<<"front is "<<q.getFront()<<endl;
  q.pop();
  q.pop();
  q.print();
  return 0;
}