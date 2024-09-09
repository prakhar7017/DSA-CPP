class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 0;
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }
        int size = n / k; // required size of each part
        int rem = n % k;  // left out remainder to be adjusted 
        vector<ListNode*> res(k,NULL);
        ListNode* current = head;
        
        for (int i = 0; i < k; i++) {
            if (current == NULL) break; 
            res[i] = current;
            int part_size = size;
            if (rem > 0) {
                part_size++; 
                rem--;
            }
            for (int j = 1; j < part_size; j++) {
                current = current->next;
            }
            ListNode* next = current->next;
            current->next = NULL;
            current = next;
        }
        return res;
    }
};