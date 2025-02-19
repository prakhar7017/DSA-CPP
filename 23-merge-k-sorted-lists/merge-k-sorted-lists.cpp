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
    ListNode* merge(vector<ListNode*>& lists){
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(auto list:lists){
            if(list) pq.push({list->val,list});
        }

        ListNode* dummyNode= new ListNode(-1);
        ListNode* temp=dummyNode;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int value=top.first;
            ListNode* node=top.second;
            temp->next=node;
            temp=temp->next;
            if(node->next){
                pq.push({node->next->val,node->next});
            }
        }
        return dummyNode->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists);
    }
};