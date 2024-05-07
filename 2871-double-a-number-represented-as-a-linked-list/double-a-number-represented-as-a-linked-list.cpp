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
public:
    int carry=0;
    ListNode* solve(ListNode* head){
         // base case
        if(!head || !head->next){
            int value=head->val*2;
            int sum=value%10;
            carry=value/10;
            head->val=sum;
            return head;
        }
        ListNode* nextNode=solve(head->next);

        int value=head->val*2;
        int sum=(value%10)+carry;
        carry=value/10;
        head->val=sum;
        head->next=nextNode;
        return head;
    }
    ListNode* doubleIt(ListNode* head) {
        head=solve(head);
        if(carry!=0){
            ListNode* ans=new ListNode(carry);
            ans->next=head;
            return ans;
        }
        return head;

    }
};