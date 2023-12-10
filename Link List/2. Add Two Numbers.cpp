// My Solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        int carry=0;
        ListNode* dummy= new ListNode(-1);
        ListNode* curr= dummy;
        while(l1 && l2){
            int sum=l1->val+l2->val+carry;
            int digit=sum%10;
            ListNode* newNode=new ListNode(digit);
            carry=sum/10;
            curr->next=newNode;
            curr=newNode;
            l1=l1->next;
            l2=l2->next;
        }

        while(l1){
            if(carry){
                int sum=l1->val+carry;
                ListNode* newNode=new ListNode(sum%10);
                carry=sum/10;
                curr->next=newNode;
                curr=newNode;
                l1=l1->next;
            }else{
                ListNode* newNode=new ListNode(l1->val);
                carry=l1->val/10;
                curr->next=newNode;
                curr=newNode;
                l1=l1->next;   
            }
        }
        while(l2){
            if(carry){
                int sum=l2->val+carry;
                ListNode* newNode=new ListNode(sum%10);
                carry=sum/10;
                curr->next=newNode;
                curr=newNode;
                l2=l2->next;
            }else{
                ListNode* newNode=new ListNode(l2->val);
                carry=l2->val/10;
                curr->next=newNode;
                curr=newNode;
                l2=l2->next;   
            }
        }
        if(carry){
                ListNode* newNode=new ListNode(carry);
                curr->next=newNode;
                curr=newNode;
        }
        return dummy->next;
    }
};

// Better Solution
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;

    while (l1 || l2 || carry) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10;

        curr->next = new ListNode(sum % 10);
        curr = curr->next;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return dummy->next;
}