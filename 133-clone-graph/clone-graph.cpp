class Solution {
public:
    unordered_map<Node*, Node*> mp;
    void DFS(Node* node, Node* cloneNode) {
        for(Node* neighNode:node->neighbors){
            if(mp.find(neighNode)==mp.end()){
                Node* clonedNeighNode = new Node(neighNode->val);
                mp[neighNode]=clonedNeighNode;
                cloneNode->neighbors.push_back(clonedNeighNode);
                DFS(neighNode,clonedNeighNode);
            }else{
                cloneNode->neighbors.push_back(mp[neighNode]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        mp.clear();
        Node* clonedNode = new Node(node->val);
        mp[node] = clonedNode;
        DFS(node, clonedNode);
        return clonedNode;
    }
};