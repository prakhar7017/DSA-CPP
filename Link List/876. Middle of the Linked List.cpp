/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    private:
    int getLen(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int n=getLen(head);
        int position=n/2+1;
        int currPosi=1;
        ListNode* temp=head;
        while(currPosi!=position){
            currPosi++;
            temp=temp->next;
        }
        return temp;
    }
};

time complexity:O(n)
space complexity:O(1);

// -------------------OR---------------------
// slow fast approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }
};