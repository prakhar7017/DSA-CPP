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

    void BFS(queue<Node*>&q){
        while(!q.empty()){
            Node* currNode = q.front();
            Node* clonedNode = mp[currNode];
            q.pop();

            for(Node* neighNode: currNode->neighbors){
                if(mp.find(neighNode)==mp.end()){
                    Node* clonedNeighNode = new Node(neighNode->val);
                    mp[neighNode]=clonedNeighNode;
                    clonedNode->neighbors.push_back(clonedNeighNode);
                    q.push(neighNode);
                }else{
                    clonedNode->neighbors.push_back(mp[neighNode]);
                }
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        mp.clear();
        Node* clonedNode = new Node(node->val);
        mp[node] = clonedNode;
        // DFS(node, clonedNode);
        queue<Node*> que;
        que.push(node);
        BFS(que);
        return clonedNode;
    }
};