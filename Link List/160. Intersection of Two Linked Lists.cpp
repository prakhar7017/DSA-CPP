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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;

        while(a->next && b->next){
            if(a==b){
                return a;
            }
            a=a->next;
            b=b->next;
        }

        if(a->next ==NULL && b->next==NULL && a!=b){
            return NULL;
        }

        if(a->next==NULL){
            int LenB=0;
            while(b->next!=NULL){
                LenB++;
                b=b->next;
            }

            while(LenB--){
                headB=headB->next;
            }
        }else{
            int LenA=0;
            while(a->next!=NULL){
                LenA++;
                a=a->next;
            }

            while(LenA--){
                headA=headA->next;
            }
        }

        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};

time complexity: O(n)
space complexity: O(1)

