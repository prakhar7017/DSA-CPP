class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return head;
        }
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        for(int i=1;i<=n;i++){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* temp=slow->next;
        slow->next=temp->next;
        temp->next=NULL;
        delete temp;
        return dummy->next;
    }
};

// time complexity:O(n)
// space complexity:O(1)