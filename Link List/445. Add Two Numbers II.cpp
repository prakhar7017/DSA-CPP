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

// without reversing i.e using stack
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        stack<int>s1;
        stack<int>s2;
        while(l1 || l2){
            if(l1){
                s1.push(l1->val);
                l1=l1->next;
            }
            if(l2){
                s2.push(l2->val);
                l2=l2->next;
            }
        }
        int sum=0;
        int carry=0;
        ListNode* ans=new ListNode(-1);
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){
                sum+=s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum+=s2.top();
                s2.pop();
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