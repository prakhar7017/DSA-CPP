#include <iostream>
using namespace std;

class Stack{
  public:
    int* arr;
    int size;
    int top;

    Stack(int size){
      arr=new int[size];
      this->size=size;
      this->top=-1;
    }

    void push(int data){
      if(top==size-1){
        cout<<"Stack is overflow"<<endl;
        return;
      }else{
        top++;
        arr[top]=data;
      }
    }

    void pop(){
      if(top==-1){
        cout<<"Stack is underflow"<<endl;
        return;
      }else{
        top--;
      }
    }

    bool isEmpty(){
      if(top==-1){
        return true;
      }else{
        return false;
      }
    }

    int getTop(){
      if(top==-1){
        cout<<"Stack is underflow"<<endl;
        return -1;
      }else{
        return arr[top];
      }
    }
    
    int getSize(){
      return top+1;
    }

    void print(){
      cout<<"Stack: "<<top<<endl;
      cout<<"Top Element:"<<getTop()<<endl;
      cout<<"Stack: ";
      for(int i=0;i<getSize();i++){
        cout<<arr[i]<<" ";
      }
      cout<<endl;
    }
};

int main() {

  Stack st(8);

  st.push(10);
  st.print();

  st.push(20);
  st.print();

  cout<<endl<<"Top element: "<<st.getTop()<<endl;
  cout<<endl<<"Size of Stack: "<<st.getSize()<<endl;

  st.pop();
  st.pop();

  if(st.isEmpty()){
    cout<<"Empty"<<endl;
  }else{
    cout<<"Not Empty"<<endl;
  }

  st.push(40);
  st.print();

  st.push(50);
  st.print();

  return 0;
}