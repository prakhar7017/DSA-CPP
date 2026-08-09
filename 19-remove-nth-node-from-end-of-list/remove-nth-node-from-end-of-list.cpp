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
    int listLength(ListNode* head){
        if(!head) return 0;
        ListNode* curr = head;
        int len = 0;
        while(curr){
            len++;
            curr = curr->next;
        }
        return len;
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
    ListNode* better(ListNode* head, int n){
        if(!head) return head;
        int len = listLength(head);
        int fromStart = len - n +1;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        for(int i = 1;i<fromStart;i++){
            prev = curr;
            curr = curr ->next;
        }

        if(prev ==  nullptr){
            head = head->next;
        }else{
            prev->next = curr -> next;
        }

        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return better(head,n);   
    }
};