/*
    Delete node in Doubly Linked List

    Given a doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

*/

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        int pos=1;
        Node* temp=head;
        while(pos!=x){
            temp=temp->next;
            ++pos;
        }
        
        if(temp!=nullptr){
            if(temp==head){
                head=head->next;
                delete temp;
            }else{
                if(temp->prev!=nullptr){
                    temp->prev->next=temp->next;
                }
                if(temp->next!=nullptr){
                    temp->next->prev=temp->prev;
                }
                delete temp;
            }
        }
        return head;
    }
};

// time complexity:o(n);
// space complexity:o(1);
