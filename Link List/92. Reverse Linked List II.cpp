class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
            if (!head || !head->next || left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* beforeLeft = dummy;

        // Move to the node just before the sublist to be reversed
        for (int i = 1; i < left; ++i) {
            beforeLeft = beforeLeft->next;
        }

        ListNode* prev = nullptr;
        ListNode* current = beforeLeft->next;
        ListNode* next = nullptr;

        // Reverse the sublist
        for (int i = 0; i <= right - left; ++i) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        // Connect the reversed sublist back to the original list
        beforeLeft->next->next = current;
        beforeLeft->next = prev;

        return dummy->next;

    }
};
// time complexity:O(n)
