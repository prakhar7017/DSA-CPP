class Solution {
    private:
    ListNode* findMiddle(ListNode* &head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL){
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }
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
    void reorderList(ListNode* head) {
        if(!head) return ;

        ListNode* middle=findMiddle(head);
        ListNode* temp=middle->next;
        middle->next=NULL;

        ListNode* secondHead=reverse(temp);

        ListNode* firstHead=head;
        while(secondHead){
            ListNode* nextFirstHead=firstHead->next;
            ListNode* nextSecondHead=secondHead->next;

            firstHead->next=secondHead;
            secondHead->next=nextFirstHead;

            firstHead=nextFirstHead;
            secondHead=nextSecondHead;
        }
    }
};

// time complexity:O(n)



//-----------------------------------------------------------------------------------
// using stack 
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        
        ListNode* curr = head;
        while(curr) {
            st.push(curr);
            curr = curr->next;
        }
        
        int k = st.size()/2;
        curr = head;
        while(k--) {
            ListNode* topNode = st.top();
            st.pop();
            
            ListNode* temp = curr->next;
            curr->next = topNode;
            topNode->next = temp;
            curr = temp;
        }
        
        curr->next = NULL;
    }
};

// time complexity o(n)
// space complixity o(n)


//------------------------------------------------------------------------------------
// using recursion stack
class Solution {
public:
    ListNode* curr;
    
    void solve(ListNode* head) {
        if(!head) {
            return;
        }
        
        solve(head->next);
        ListNode* tempn = curr->next;
        if(tempn == NULL) {
            return;
        } else if(head == curr) {
            head->next = NULL;
            return;
        }
        
        curr->next = head;
        head->next = tempn == head ? NULL : tempn;
        
        curr = tempn;
    }
    
    void reorderList(ListNode* head) {
        curr = head;
        solve(head);
    }
};