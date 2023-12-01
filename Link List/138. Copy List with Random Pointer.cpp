

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