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
    ListNode* reverse(ListNode* &head){
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
public:
    int getDecimalValue(ListNode* head) {
        if(!head){
            return 0;
        }
        ListNode* reverseList=reverse(head);
        ListNode* temp=reverseList;
        int base=1;
        int decimal=0;
        while(temp!=NULL){
            int lastDigit=temp->val;
            decimal+=lastDigit*base;
            base*=2;
            temp=temp->next;
        }

        return decimal;

    }
};