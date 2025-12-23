class Solution {
public:
    int n;
    void bfs(vector<int>& edges,int node,vector<int>&dist){
        queue<int>q;
        q.push(node);
        dist[node]=0;
        vector<bool>vis(n,false);
        vis[node]=true;

        while(!q.empty()){
            int currNode  = q.front();
            q.pop();

            int v = edges[currNode];
            if(v!=-1 && !vis[v]){
                dist[v]=dist[currNode]+1;
                vis[v]=true;
                q.push(v);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        vector<int>dist_1(n,INT_MAX);
        vector<int>dist_2(n,INT_MAX);
        bfs(edges,node1,dist_1);
        bfs(edges,node2,dist_2);

        int minDistNode =-1;
        int minDistTillNow=INT_MAX;

        for(int i=0;i<n;i++){
            int maxD = max(dist_1[i],dist_2[i]);
            if(minDistTillNow>maxD){
                minDistTillNow=maxD;
                minDistNode=i;
            }
        }
        return minDistNode;
    }
};