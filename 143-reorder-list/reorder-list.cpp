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
class Solution {
public:
    void bruteForce(ListNode* head){
        if(!head || !head->next) return;

        ListNode* curr = head;

        while(curr && curr->next){
            ListNode* prevLast = nullptr;
            ListNode* last = curr;

            while(last->next){
                prevLast = last;
                last = last -> next;
            }

            if(curr->next == last) break;

            prevLast->next = nullptr;
            ListNode* next = curr->next;
            curr->next = last;
            last->next = next;

            curr = next;
        }
        return;
    }

    void reorderListArray(ListNode* head){
        if(!head || !head->next) return;
        vector<ListNode*>nodes;

        ListNode* curr = head;

        while(curr){
            nodes.push_back(curr);
            curr = curr->next;
        }

        int s = 0;
        int e = nodes.size()-1;

        while(s<e){
            nodes[s]->next = nodes[e];
            s++;
            if(s==e) break;
            nodes[e]->next = nodes[s];
            e--;
        }

        nodes[s]->next=nullptr;
    }

    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseL(ListNode* head){
        if(!head) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev =  curr;
            curr = next;

        }
        return prev;
    }
    void merge(ListNode* h1,ListNode* h2){
        while(h2){
            ListNode* n1 = h1->next;
            ListNode* n2 = h2->next;
            h1->next = h2;
            h2->next = n1;

            h1 =  n1;
            h2 =  n2;
        }
    }
    void reorderList(ListNode* head) {
        // reorderListArray(head);
        if(!head || !head->next) return;

        ListNode* middle = findMiddle(head);

        ListNode* second = middle->next;
        middle->next = nullptr;

        ListNode* reverse = reverseL(second);
        
        merge(head,reverse);
    }
};