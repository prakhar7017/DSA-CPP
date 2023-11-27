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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;

        if(!list2) return list1;

        ListNode* ans=new ListNode(-1);
        ListNode* mptr=ans;

        while(list1 && list2){
            if(list1->val<=list2->val){
                mptr->next=list1;
                mptr=list1;
                list1=list1->next;
            }else{
                mptr->next=list2;
                mptr=list2;
                list2=list2->next;
            }
        }

        if(list1){
            mptr->next=list1;
        }
        if(list2){
            mptr->next=list2;
        }

        return ans->next;
    }
};

// ----------------------------OR---------------------------------
// recursion approach
class Solution {
    private:
    ListNode* mergeList(ListNode*&a,ListNode*&b){
        if(!a) return b;
        if(!b) return a;

        ListNode* ans=0;
        if(a->val<=b->val){
            ans=a;
            a->next=mergeList(a->next,b);
        }else{
            ans=b;
            b->next=mergeList(a,b->next);
        }

        return ans;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return mergeList(list1,list2);
    }
};

// time complexity:O(n)
// space complexity:O(1)

// https://leetcode.com/problems/merge-two-sorted-lists/

