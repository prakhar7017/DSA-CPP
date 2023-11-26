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
    int getLen(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextNode=NULL;
        int position=0;
        int len=getLen(head);
        if(len<k){
            return head;
        }   
        // 1 grp reverse
        while(position<k){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
            position++;
        }
        if(nextNode!=NULL){
            ListNode* recAns=reverseKGroup(nextNode,k);
            head->next=recAns;
        }     
        return prev;
    }
};

// time complexity:O(n)
// space complexity:O(1)

// key note: 
//    remember:
//    1:head->next=recAns;

//    2: return prev;

//    3:len conditon to check id len<k return head;