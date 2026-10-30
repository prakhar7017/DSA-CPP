/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copy1(Node* head) {
        unordered_map<Node*, Node*> mp;

        Node* newHead = nullptr;
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
            Node* newNode = new Node(curr->val);
            mp[curr] = newNode;
            if (newHead != nullptr) {
                prev->next = newNode;
                prev = newNode;
            } else {
                newHead = newNode;
                prev = newNode;
            }
            curr = curr->next;
        }

        curr = head;
        Node* newCurr = newHead;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                newCurr->random = mp[curr->random];
            }
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
    Node* copy2(Node* head) {
        if (head == nullptr)
            return nullptr;

        Node* curr = head;
        // A->B
        while (curr != nullptr) {
            Node* newNode = new Node(curr->val); // X
            Node* currNext = curr->next;         // B
            curr->next = newNode;                // A->X
            curr->next->next = currNext;         // B A->X->B
            curr = currNext;
        }

        curr = head;
        while (curr != nullptr) {
            if (curr->random == nullptr) {
                curr->next->random = nullptr;
            } else {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node* newCurr = head->next;
        Node* newHead = head->next;

        while (curr && newCurr) {
            curr->next = curr->next == nullptr ? nullptr : curr->next->next;
            newCurr->next =
                newCurr->next == nullptr ? nullptr : newCurr->next->next;
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
    Node* copyRandomList(Node* head) { return copy2(head); }
};