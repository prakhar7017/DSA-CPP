/*
    Add two numbers represented by linked lists

    Given two numbers, num1 and num2, represented by linked lists of size n and m respectively. The task is to return a linked list that represents the sum of these two numbers.

    For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

    Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.
*/
class Solution {
public:
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* temp=nullptr;
        while(curr && curr->data==0){
            temp=curr;
            curr=curr->next;
        }
        if(temp!=nullptr){
            temp->next=nullptr;
        }
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* addTwoLists(Node* num1, Node* num2) {
        Node* l1 = reverse(num1);
        Node* l2 = reverse(num2);
        int carry = 0;
        Node* ans = nullptr;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->data;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->data;
                l2 = l2->next;
            }
            carry = sum / 10;
            sum = sum % 10; 
            Node* newNode = new Node(sum);
            newNode->next = ans;
            ans = newNode;
        }
        return ans==nullptr ? new Node(0) : ans;
    }
};

// time complexity: O(n+m)
// space complexity: O(1)