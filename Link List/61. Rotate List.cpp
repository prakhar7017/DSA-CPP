class Solution {
    private:
    int getLen(ListNode* head){
        int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return 0;
        }

        int len=getLen(head);

        int actualK=(k%len);

        if(actualK==0){
            return head;
        }

        int newLastPos=len-actualK;
        ListNode* newLastNode=head;
        for(int i=1;i<newLastPos;i++){
            newLastNode=newLastNode->next;
        }
        ListNode* newHead=newLastNode->next;
        newLastNode->next=NULL;

        ListNode* it=newHead;
        while(it->next){
            it=it->next;
        }
        it->next=head;
        return newHead;
    }
};

// time complexity:O(n) space complexity:O(1)
// https://leetcode.com/problems/rotate-list/
