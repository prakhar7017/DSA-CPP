class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return head;
        }
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        for(int i=1;i<=n;i++){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* temp=slow->next;
        slow->next=temp->next;
        temp->next=NULL;
        delete temp;
        return dummy->next;
    }
};
// one pass solution without dummy node
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=1;i<=n;i++){ // move fast n steps ahead
            fast=fast->next;
        }
        if(fast==NULL){ // means delete head
            ListNode* temp=head->next;
            head->next=NULL;
            delete(head);
            return temp;
        }
        while(fast->next!=NULL){ // move fast and slow together till fast reaches end
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* temp=slow->next; 
        slow->next=temp->next;
        temp->next=NULL;
        delete(temp);
        return head;
    }
};
// time complexity:O(n)
// space complexity:O(1)

// 2 pass solution
class Solution {
public:
    int getLen(ListNode* &head){
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=getLen(head);

        if(n==len) return head->next; // means delete head

        int frontTravel=len-n;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(frontTravel--){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        temp->next=NULL;
        delete(temp);
        return head;
    }
};