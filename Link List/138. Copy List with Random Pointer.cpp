

class Solution {
    private:
    Node* helper(Node* &head,unordered_map<Node*,Node*>&mp){
        if(!head) return 0;

        Node* newHead=new Node(head->val);
        mp[head]=newHead;
        newHead->next=helper(head->next,mp);

        //list copy done

        if(head->random){
            newHead->random=mp[head->random];
        }
        return newHead;
    }
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        return helper(head,mp);
    }
};

// time complexity: O(N2)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return 0;
        // clone A to A'
        Node* it=head;
        while(it){
            Node* cloneNode=new Node(it->val);
            cloneNode->next=it->next;
            it->next=cloneNode;
            it=it->next->next;
        }

        // assign ramdom pointers
        it=head;
        while(it){
            Node* cloneNode=it->next;
            cloneNode->random=it->random ? it->random->next : NULL;

            it=it->next->next;
        }

        // detach A' from A
        it=head;
        Node* cloneHead=it->next;
        while(it){
            Node* cloneNode=it->next;
            it->next=it->next->next;
            if(cloneNode->next){
                cloneNode->next=cloneNode->next->next;
            }
            it=it->next;
        }
        return cloneHead;
    }
};

// time complexity: O(n)