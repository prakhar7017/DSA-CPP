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
        if(!head) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* bruteForce(ListNode* head, int n){
        if(!head) return head;

        // 1 reverse list
        ListNode* rev = reverse(head);
        // 2 find nth node
        ListNode* prevN = nullptr;
        ListNode* curr = rev;
        for(int i=1;i<n;i++){
            prevN = curr;
            curr = curr ->next;
        }
        if(prevN ==  nullptr){
            rev = rev->next;
        }else{
            prevN->next = curr -> next;
        }
        // 3 again reverse
        return reverse(rev);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return bruteForce(head,n);   
    }
};