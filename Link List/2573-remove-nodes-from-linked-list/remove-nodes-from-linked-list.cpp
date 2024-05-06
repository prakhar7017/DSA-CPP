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
//-----------------------------------------------------------------------------------
// Method 1 using Recursion to go at the end of list and then unwinding
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* nextNode=removeNodes(head->next);

        if(head->val<nextNode->val){
            delete head;
            return nextNode;
        }
        head->next=nextNode;
        return head;
    }
};

// time complexity: O(n)
// space complexity: O(n)

//-----------------------------------------------------------------------------------

// Method 2 using Stack
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode* >st;
        ListNode* curr=head;
        while(curr!=nullptr){
            st.push(curr);
            curr=curr->next;
        }

        ListNode* topNode=st.top();
        st.pop();
        ListNode* newHead=topNode;
        int maxV=topNode->val;
        curr=nullptr;
        while(!st.empty()){
            curr=st.top();
            st.pop();
            if(curr->val<maxV){
                continue;
            }else{
                maxV=max(curr->val,maxV);
                curr->next=newHead;
                newHead=curr;
            }
        }
        return newHead;
    }
};

// time complexity : o(n)
// space complexity :o(1)

//-----------------------------------------------------------------------------------

// Method 3  using reversing the list
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head=reverse(head);
        int maxV=INT_MIN;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
            maxV=max(maxV,curr->val);
            if(curr->val<maxV){
                prev->next=curr->next;
                ListNode* temp=curr;
                curr=curr->next;
                delete temp;
            }else{
                prev=curr;
                curr=curr->next;
            }
        }
        return reverse(head);
    }
};

// time complexity: O(n)
// space complexity: O(1)

//-----------------------------------------------------------------------------------