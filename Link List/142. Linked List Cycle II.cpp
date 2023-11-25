/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    private:
    ListNode* iscyclePresnt(ListNode* &head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
            if(slow==fast){
                return fast;
            }
        }
        return NULL;
    }
    ListNode* startPoint(ListNode* &head){
        ListNode* ispresentNode=iscyclePresnt(head);
        if(ispresentNode==NULL){
            return NULL;
        }
        ListNode* slow=head;
        while(slow!=ispresentNode){
            slow=slow->next;
            ispresentNode=ispresentNode->next;
        }
        return slow;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        return startPoint(head);
    }
};

// time complexity:O(n)
// space complexity:O(1)
