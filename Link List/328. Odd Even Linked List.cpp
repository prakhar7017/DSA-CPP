class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            // NULL or X->NULL
            return head;
        }
        ListNode* h1=head;
        ListNode* h2=head->next;
        ListNode* evenHead=h2;

        while(h2 &&  h2->next){
            h1->next=h2->next;
            h2->next=h2->next->next;
            h1=h1->next;
            h2=h2->next;
        }

        h1->next=evenHead;
        
        return head;
    }
};
// time complexity:O(n) space complexity:O(1)
