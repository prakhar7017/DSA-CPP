class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* curr=head;
        while(curr){
            if(curr->val==val){
                ListNode* nextNode=curr->next;
                prev->next=nextNode;
            }else{
                prev=curr;
            }
            if(curr){
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};

// time complexity: O(n)