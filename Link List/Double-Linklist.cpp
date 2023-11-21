#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node* prev;

  Node(){
    this->data=0;
    this->next=NULL;
    this->prev=NULL;
  }

  Node(int data){
    this->data=data;
    this->next=NULL;
    this->prev=NULL;
  }
};
void printLL(Node* head){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<endl;
}

int findLen(Node* head){
  Node* temp=head;
  int count=0;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
  return count;
}

void insertAtHead(Node* &head,Node* tail,int data){
  if(head==NULL){
    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
  }else{
    Node* newNode=new Node(data);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
  }
}

void insertAtTail(Node* &head,Node* &tail,int data){
  if(head==NULL){
    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
  }else{
    Node* newNode=new Node(data);
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
  }
}

void insertAtPosition(int data,int position,Node* &head,Node* &tail){
  if(head==NULL){
    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
  }else{
    int len=findLen(head);
    if(position==1){
      insertAtHead(head,tail,data);
    }else if(position>len){
      insertAtTail(head,tail,data);
    }else{
      Node* newNode=new Node(data);
      Node* prevNode=NULL;
      Node* currNode=head;
      while(position!=1){
        prevNode=currNode;
        currNode=currNode->next;
        position--;
      }
      prevNode->next=newNode;
      newNode->prev=prevNode;
      newNode->next=currNode;
      currNode->prev=newNode;
    }
  }
}

void deleteNode(Node* &head,Node* &tail,int position){
  if(head==NULL){
    cout<<"empty list"<<endl;
    return;
  }
  if(head==tail){
    Node* temp=head;
    delete temp;
    head=NULL;
    tail=NULL;
  }
  int len=findLen(head);
  if(position==1){
    Node* temp=head;
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
    delete temp;
  }else if(position==len){
    Node* prevNode=tail->prev;
    prevNode->next=NULL;
    tail->prev=NULL;
    delete tail;
    tail=prevNode;
  }else{
    Node* prevNode=NULL;
    Node* currNode=head;
    while(position!=1){
      prevNode=currNode;
      currNode=currNode->next;
      position--;
    }
    Node* nextNode=currNode->next;
    prevNode->next=nextNode;
    nextNode->prev=prevNode;
    currNode->next=NULL;
    currNode->prev=NULL;
    delete currNode;
  }
}
int main() {
  Node* head=NULL;
  Node* tail=NULL;

  insertAtPosition(50,1,head,tail);
  insertAtPosition(40,1,head,tail);
  insertAtPosition(30,1,head,tail);
  insertAtPosition(20,1,head,tail);
  insertAtPosition(10,1,head,tail);
  insertAtPosition(60,10,head,tail);
  insertAtPosition(70,10,head,tail);
  insertAtPosition(45,5,head,tail);
  insertAtPosition(65,8,head,tail);

  int len=findLen(head);
  cout<<"length->"<<len<<endl;

  cout<<"before deletion"<<endl;
  printLL(head);

  cout<<"after deletion"<<endl;
  deleteNode(head,tail,9);
  printLL(head);

  return 0;
}