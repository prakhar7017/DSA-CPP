class Solution {
    private:
    ListNode* findMiddle(ListNode* &head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL){
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }
    ListNode* reverse(ListNode* &head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(!head) return ;

        ListNode* middle=findMiddle(head);
        ListNode* temp=middle->next;
        middle->next=NULL;

        ListNode* secondHead=reverse(temp);

        ListNode* firstHead=head;
        while(secondHead){
            ListNode* nextFirstHead=firstHead->next;
            ListNode* nextSecondHead=secondHead->next;

            firstHead->next=secondHead;
            secondHead->next=nextFirstHead;

            firstHead=nextFirstHead;
            secondHead=nextSecondHead;
        }
    }
};

// time complexity:O(n)