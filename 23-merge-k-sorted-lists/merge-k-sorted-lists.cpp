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
    ListNode* convertArrintoLL(vector<int>& arr){
        int n= arr.size();
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp=dummyNode;
        for(int i=0;i<n;i++){
            ListNode* newNode=new ListNode(arr[i]);
            temp->next=newNode;
            temp=newNode;
        }

        return dummyNode->next;
    }
    ListNode* solveUsingBruteForce(vector<ListNode*>& lists){
        int k = lists.size();
        vector<int>arr;
        for(int i=0;i<k;i++){
            ListNode* node = lists[i];
            while(node){
                int value= node->val;
                arr.push_back(value);
                node=node->next;
            }
        }
        sort(begin(arr),end(arr));

        return convertArrintoLL(arr);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return solveUsingBruteForce(lists);
    }
};