class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* c1=NULL;
        ListNode* c2=NULL;
        ListNode* temp=list1;
        int count=0;
        while(temp!=NULL){
            if(count==a-1){
                c1=temp;
            }
            if(count==b) c2=temp;
            count++;
            temp=temp->next;
        }

        c1->next=list2;

        temp=list2;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=c2->next;

        c2->next=NULL;

        return list1;
    }
};

// time complexity:o(n+m)
// space complexity:o(1)