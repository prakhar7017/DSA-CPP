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

iteravtie approach:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextNode=NULL;
        while(curr!=NULL){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
};

time complexity:O(n)
space complexity:O(1)

// ----------------------------------------------------------

recursive approach:

class Solution {
    private:
    ListNode* reverseListHelper(ListNode* &prev,ListNode* curr){
        //base case
        if(curr==NULL){
            return prev;
        }

        // 1 case
        ListNode* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;

        // revursive call
        return reverseListHelper(prev,curr);
    }
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        return reverseListHelper(prev,curr);
    }
};