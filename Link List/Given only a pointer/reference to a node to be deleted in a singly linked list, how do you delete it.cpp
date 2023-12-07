#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void push(int data, Node* &head, Node* &tail) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    } else {
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

void printLL(Node* head) {
    if (head == NULL) {
        return;
    } else {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;  
        }
    }
    cout << endl;
}

void deleteNode(Node* curr){
  if(curr==NULL){
    return;
  }else if(curr->next==NULL){
    Node* dummy=new Node(-1);
    curr->data=dummy->data;
    curr->next=dummy->next;
    delete dummy;
  }
  else{
    Node* temp=curr->next;
    curr->data=temp->data;
    curr->next=temp->next;
    temp->next=NULL;
    delete temp;
  }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    push(1, head, tail);
    push(2, head, tail);
    push(3, head, tail);
    push(4, head, tail);
    push(5, head, tail);
    printLL(head);

    int pos=5;
    Node* node=head;
    while(pos!=1){
      node=node->next;
      pos--;
    }
    cout<<"Node to be deleted "<<node->data<<endl;

    deleteNode(node);

    cout<<"after deletion"<<endl;

    printLL(head);
    return 0;
}
