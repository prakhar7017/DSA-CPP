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
    ListNode* mergeList(ListNode* &a, ListNode* &b) {
        if (!a) return b;
        if (!b) return a;

        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        while (a && b) {
            if (a->val <= b->val) {
            mptr->next = a;
            mptr = a;
            a = a->next;
            } else {
            mptr->next = b;
            mptr = b;
            b = b->next;
            }
        }

        while (a) {
            mptr->next = a;
            mptr = a;
            a = a->next;
        }

        while (b) {
            mptr->next = b;
            mptr = b;
            b = b->next;
        }

        return ans->next;
    }
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* middle=getMid(head);
        ListNode* left=head;
        ListNode* right=middle->next;
        middle->next=NULL;

        left=sortList(left);
        right=sortList(right);

        return mergeList(left,right); 
    }
};