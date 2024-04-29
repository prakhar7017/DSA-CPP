/*
    Remove every kth node

    Given a singly linked list having n nodes, your task is to remove every kth node from the linked list. 

*/

class Solution {
    public:
    Node* deleteK(Node *head,int K){
        if(!head || K==1) return nullptr;
        
        int count=1;
        Node* prev=nullptr;
        Node* curr=head;
        while(curr!=nullptr){
            Node* temp=nullptr;
            if(count==K){
                prev->next=curr->next;
                temp=curr;
                count=0;
            }else{
                prev=curr;
            }
            ++count;
            curr=curr->next;
            delete temp;
        }
        return head;
    }
};

// time complexity: O(n)
// space complexity: O(1)