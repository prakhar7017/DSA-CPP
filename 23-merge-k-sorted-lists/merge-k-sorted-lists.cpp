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
    ListNode* convertArrintoLL(vector<int>& arr) {
        int n = arr.size();
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        for (int i = 0; i < n; i++) {
            ListNode* newNode = new ListNode(arr[i]);
            temp->next = newNode;
            temp = newNode;
        }

        return dummyNode->next;
    }
    ListNode* solveUsingBruteForce(vector<ListNode*>& lists) {
        int k = lists.size();
        vector<int> arr;
        for (int i = 0; i < k; i++) {
            ListNode* node = lists[i];
            while (node) {
                int value = node->val;
                arr.push_back(value);
                node = node->next;
            }
        }
        sort(begin(arr), end(arr));

        return convertArrintoLL(arr);
    }

    ListNode* mergeTwoLL(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLL(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLL(l1, l2->next);
            return l2;
        }
        return nullptr;
    }

    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists) {
        if(start>end) return nullptr;

        if(start==end) return lists[start];

        int mid = start + (end - start) / 2;

        ListNode* L1 = partitionAndMerge(start, mid, lists);
        ListNode* L2 = partitionAndMerge(mid + 1, end, lists);

        return mergeTwoLL(L1,L2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // return solveUsingBruteForce(lists);
        return partitionAndMerge(0,lists.size()-1,lists);
    }
};