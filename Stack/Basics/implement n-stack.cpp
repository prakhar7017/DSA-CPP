#include <iostream>
using namespace std;

class NStack{
  int *a ,*top,*next;
  int n; // no fof stacks
  int size; // size of main array
  int freespot; // tells free space availabe in main array by storing index 
  public:
    NStack(int _n,int _s) : n(_n) , size(_s){
      freespot=0;
      a=new int[size];
      top=new int[n]; // it stores the index of top element of the ith stack

      next=new int[size]; // it performs two things
                          // a: stores the index of next element after top element, 
                          // b: point to next freespot
                          // before storing a value at main array  it behaves as b and after storing value at main array it behaves as a, for a particular element

      for(int i=0;i<n;i++){
        top[i]=-1; // initial [-1,-1,-1] which means all stack are empty 
      }

      for(int i=0;i<size;i++){
        next[i]=i+1;// initially [1,2,3,4,5,6]
                            //  0,1,2,3,4,5   indexes                
      }

      next[size-1]=-1; // last element of next always have value -1 ,[1,2,3,4,5,-1]
    }
    
    bool push(int x,int m){
      if(freespot==-1){
        return false; // stack overflow
      }
      // 1 find index to insert
      int index=freespot;
      // 2 update freespot
      freespot=next[index];
      // 3 insert x at main array
      a[index]=x;
      // 4 update next 
      next[index]=top[m-1];
      // 5 update top
      top[m-1]=index;

      return true ; // update successful
    }

    int pop(int m){
      if(top[m-1]==-1){
        return -1; // stack underflow
      }
      // 1 find index of top element  from top array 
      int index=top[m-1];
      // 2 update top now it store next element after top element
      top[m-1]=next[index];
      // 3 store element which is going to be poped
      int poppedElement=a[index];
      // 4 now next will store freespot 
      next[index]=freespot;
      // 5 update freepot
      freespot=index;

      return poppedElement;
    }

    void print(){
      cout<< "Main Array "; 
      for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
      }
      cout<<endl;
      cout<< "Top Array "; 
      for(int i=0;i<n;i++){
        cout<<top[i]<<" ";
      }
      cout<<endl;
      cout<< "next Array "; 
      for(int i=0;i<size;i++){
        cout<<next[i]<<" ";
      }
      cout<<endl;

    }

    ~NStack(){
      delete[] a;
      delete[] top;
      delete[] next;
    }
};




int main() {
  NStack n(3,6);
  n.push(5,1);
  n.print();
  cout<<"-------------------"<<endl;
  n.push(10,2);
  n.print();
  cout<<"-------------------"<<endl;
  n.push(6,1);
  n.print();
  cout<<"-------------------"<<endl;
  n.push(8,2);
  n.print();
  cout<<"-------------------"<<endl;
  n.push(12,3);
  n.print();

  cout<<"popping"<<endl;
  cout<<"Popped element "<<n.pop(3)<<endl;
  n.print();
  cout<<"-------------------"<<endl;
  cout<<"Popped element "<<n.pop(1)<<endl;
  n.print();
  cout<<"-------------------"<<endl;
  cout<<"Popped element "<<n.pop(1)<<endl;
  n.print();
  cout<<"-------------------"<<endl;
  cout<<"Popped element "<<n.pop(2)<<endl;
  n.print();
  cout<<"-------------------"<<endl;
  cout<<"Popped element "<<n.pop(2)<<endl;
  n.print();
  cout<<"-------------------"<<endl;
  cout<<"Popped element "<<n.pop(3)<<endl;
  n.print();
  cout<<"-------------------"<<endl;
  
  return 0;
}


// output
// Main Array 5 0 0 0 0 0 
// Top Array 0 -1 -1 
// next Array -1 2 3 4 5 -1 
// -------------------
// Main Array 5 10 0 0 0 0 
// Top Array 0 1 -1 
// next Array -1 -1 3 4 5 -1 
// -------------------
// Main Array 5 10 6 0 0 0 
// Top Array 2 1 -1 
// next Array -1 -1 0 4 5 -1 
// -------------------
// Main Array 5 10 6 8 0 0 
// Top Array 2 3 -1 
// next Array -1 -1 0 1 5 -1 
// -------------------
// Main Array 5 10 6 8 12 0 
// Top Array 2 3 4 
// next Array -1 -1 0 1 -1 -1 
// popping
// Popped element 12
// Main Array 5 10 6 8 12 0 
// Top Array 2 3 -1 
// next Array -1 -1 0 1 5 -1 
// -------------------
// Popped element 6
// Main Array 5 10 6 8 12 0 
// Top Array 0 3 -1 
// next Array -1 -1 4 1 5 -1 
// -------------------
// Popped element 5
// Main Array 5 10 6 8 12 0 
// Top Array -1 3 -1 
// next Array 2 -1 4 1 5 -1 
// -------------------
// Popped element 8
// Main Array 5 10 6 8 12 0 
// Top Array -1 1 -1 
// next Array 2 -1 4 0 5 -1 
// -------------------
// Popped element 10
// Main Array 5 10 6 8 12 0 
// Top Array -1 -1 -1 
// next Array 2 3 4 0 5 -1 
// -------------------
// Popped element -1 