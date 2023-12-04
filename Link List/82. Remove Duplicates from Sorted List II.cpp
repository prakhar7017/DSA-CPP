class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                ListNode* temp = curr;
                while (curr->next && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                ListNode* nextNode = curr->next;
                prev->next = nextNode;

                while (temp != curr) {
                    ListNode* nxtNode = temp->next;
                    temp->next = NULL;
                    delete temp;
                    temp = nxtNode;
                }
            } else {
                prev = prev->next;
            }
            if (curr) {
                curr = curr->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};