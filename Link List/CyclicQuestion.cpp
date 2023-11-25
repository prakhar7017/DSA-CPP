#include <iostream>
using namespace std;

class Node{
public:
  int data;
  Node* next;

  Node(){
    this->data=0;
    this->next=NULL;
  }
  Node(int data){
    this->data=data;
    this->next=NULL;
  }
};

void printLL(Node* head){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
  }
}

void insertAtHead(Node* &head,Node* &tail,int data){
  if(head==NULL){
    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
  }else{
    Node* newNode=new Node(data);
    newNode->next=head;
    head=newNode;
  }
}

bool isCyclePresent(Node* &head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        
        if(fast==slow){
            return true;
        }
    }
    return false;
}
Node* startingPoint(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        
        if(fast==slow){
            slow=head;
            break;
        }
    }
    
    while(slow!=fast){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}

void removeLoop(Node* &head){
    Node* slow=head;
    Node* fast=head;
    Node* stpoint=NULL;
    
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        
        if(fast==slow){
            slow=head;
            cout<<"loop is present"<<endl;
            break;
        }
    }
    while(slow!=fast){
        fast=fast->next;
        slow=slow->next;
            
        if(slow==fast){
            stpoint=slow;
            cout<<"stpoint"<<slow->data<<endl;
        }
    }
        

        
    while(stpoint->next!=slow){
        stpoint=stpoint->next;
    }
    stpoint->next=NULL;
    cout<<"removing loop from "<<stpoint->data<<endl;
}

int main() {

  Node* head=NULL;
  Node* tail=NULL;
    insertAtHead(head,tail,70);
    insertAtHead(head,tail,60);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,10);
    tail->next=head->next;
    // if(isCyclePresent(head)){
    //     cout<<"cycle present"<<endl;
    // }else{
    //     cout<<"false"<<endl;
    // }
    
    // Node* st=startingPoint(head);
    // cout<<"stpointof loop "<<st->data<<endl;
    
    // removeLoop(head);
    
    printLL(head);

  return 0;
}