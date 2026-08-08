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
    void bruteForce(ListNode* head){
        if(!head || !head->next) return;

        ListNode* curr = head;

        while(curr && curr->next){
            ListNode* prevLast = nullptr;
            ListNode* last = curr;

            while(last->next){
                prevLast = last;
                last = last -> next;
            }

            if(curr->next == last) break;

            prevLast->next = nullptr;
            ListNode* next = curr->next;
            curr->next = last;
            last->next = next;

            curr = next;
        }
        return;
    }
    void reorderList(ListNode* head) {
        bruteForce(head);
    }
};