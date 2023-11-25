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

// approach 1: using reverse list of input list and then compare both list
class Solution {
    private:
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextNode=NULL;
        while(curr!=NULL){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp1=head;
        ListNode* temp2=reverseList(head);

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val!=temp2->val){
                return false;
            }
        }
        return true;
    }
};

// time complexity:O(n)
// space complexity:O(n)

// approach 2: converting list to array and then two pointer approach
class Solution {
    private:
    bool checkPlaindrome(vector<int>&ans){
        int s=0;
        int e=ans.size()-1;
        while(s<=e){
            if(ans[s]!=ans[e]){
                return false;
            }else{
                s++;e--;
            }
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        vector<int>ans;
        ListNode* temp=head;
        while(temp!=NULL){
            ans.push_back(temp->val);
        }
        return checkPlaindrome(ans);
    }
};

// time complexity:O(n)
// space complexity:O(n)

// approach 3: using slow fast approach and then reversing second half of list and then comparing both list one by one

class Solution {
    private:
    ListNode* getMiddle(ListNode* head){
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
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextNode=NULL;
        while(curr!=NULL){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        // 1 to get middle
        ListNode* middle=getMiddle(head);
        // 2 reverse after it
        ListNode* temp=middle->next;
        middle->next=reverseList(temp);
        // to compare both half
        ListNode* temp1=head;
        ListNode* temp2=middle->next;
        while(temp2!=NULL){
            if(temp1->val!=temp2->val){
                return false;
            }
            else{
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        // reverse one more time
        temp=middle->next;
        middle->next=reverseList(temp);
        return true;
    }
};