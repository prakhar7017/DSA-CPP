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
    bool hasCycle_Helper(ListNode* &head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }

            if(slow==fast){
                return true;
            }
        }
        return false;
    }
public:
    bool hasCycle(ListNode *head) {
     return hasCycle_Helper(head);   
    }
};

time complexity:O(n)
space complexity:O(1)