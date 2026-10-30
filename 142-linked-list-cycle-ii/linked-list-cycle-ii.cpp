/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* solve(ListNode* head) {
        unordered_map<ListNode*, bool> mp; //{ node->val,0};

        ListNode* curr = head;
        while (curr != nullptr) {
            if (mp.find(curr) != mp.end()) {
                return curr;
            }
            mp[curr] = true;
            curr = curr->next;
        }
        return nullptr;
    }
    ListNode* detectCycle(ListNode* head) {return solve(head);}
};