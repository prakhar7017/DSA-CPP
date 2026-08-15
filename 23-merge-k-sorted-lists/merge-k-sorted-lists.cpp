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
    ListNode* mergeTwoList(ListNode* l1,ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* tail = dummyNode;

        while(l1 && l2){
            if(l1->val<l2->val){
                tail->next = l1;
                l1=l1->next;
            }else{
                tail->next = l2;
                l2= l2->next;
            }
            tail=tail->next;
        }

        if(l1){
            tail->next = l1;
        }
        if(l2){
            tail->next = l2;
        }

        ListNode* result = dummyNode->next;
        delete dummyNode;
        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return nullptr;

        while(k>1){
            int write = 0;
            for(int i=0;i<k;i+=2){
                if(i+1<k){
                    lists[write++] = mergeTwoList(lists[i],lists[i+1]);
                }else{
                    lists[write++]=lists[i];
                }
            }
            k = write;
            lists.resize(k);
        }
        return lists[0];
    }
};