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
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head=reverse(head);
        int maxV=INT_MIN;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
            maxV=max(maxV,curr->val);
            if(curr->val<maxV){
                prev->next=curr->next;
                ListNode* temp=curr;
                curr=curr->next;
                delete temp;
            }else{
                prev=curr;
                curr=curr->next;
            }
        }
        return reverse(head);
    }
};