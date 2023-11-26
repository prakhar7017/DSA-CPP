class Solution{
    private:
    int getLen(Node* head){
        Node* temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
    private:
    Node* reverseList(Node* head){
        Node* prev=NULL;
        Node* curr=head;
        Node* nextNode=NULL;
        while(curr!=NULL){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
public:
    int getNthFromLast(Node *head, int n)
    {
        int len=getLen(head);
        if(len<n){
            return -1;
        }
        int posi=len-n+1;
        Node* temp=head;
        while(posi!=1){
            temp=temp->next;
            posi--;
        }
        // Node* temp=reverseList(head);
        // while(n!=1){
        //     temp=temp->next;
        //     n--;
        // }
        return temp->data;
    }
};

// time complexity:O(n)
// space complexity:O(1)
