class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(!head){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        ListNode* newLastNode=NULL;
        int sum=0;
        while(fast){
            if(fast->val!=0){
                sum+=fast->val;
            }else{
                // means 2 consu. 0 nodes ke bech ka sum prepare hogya hoga
                slow->val=sum;
                newLastNode=slow;
                slow=slow->next;
                sum=0;
            }
            fast=fast->next;
        }

        ListNode* temp=slow; // storing unwanted list for deletion
        newLastNode->next=NULL; // desiredlist->next=NULL

        while(temp){ // deleting unwanted list for preventing memory leak 
            ListNode* nxt=temp->next;
            delete temp;
            temp=nxt;
        }
        return head;
    }
};

// time complexity:O(n) space complexity:O(1)
// https://leetcode.com/problems/merge-in-between-linked-lists/