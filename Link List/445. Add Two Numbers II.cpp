// basic solution
class Solution {
    private:
    ListNode* reverse(ListNode* &head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum=0;
        ListNode* L1=reverse(l1);
        ListNode* L2=reverse(l2);
        ListNode* ans=new ListNode(-1);
        while(L1 || L2){
            if(L1){
                sum+=L1->val;
                L1=L1->next;
            }
            if(L2){
                sum+=L2->val;
                L2=L2->next;
            }
            ans->val=sum%10;
            carry=sum/10;
            ListNode* newNode=new ListNode(carry);
            newNode->next=ans;
            ans=newNode;
            sum=carry;
        }

        if(carry==0){
            return ans->next;
        }else{
            return ans;
        }
    }
};