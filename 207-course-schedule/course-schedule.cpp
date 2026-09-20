class Solution {
public:
    vector<int> BFS(int u, vector<int>&vis,vector<int>&indegree,unordered_map<int,vector<int>>&adj){
        queue<int>q;
        for(int i=0;i<indegree.size();i++) if(indegree[i]==0) q.push(i);
        vector<int>ans;
        while(!q.empty()){
            int curr = q.front();q.pop();
            ans.push_back(curr);
            for(int &v:adj[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        vector<int>vis(numCourses,0);
        for(vector<int>&prerequisite:prerequisites){
            adj[prerequisite[1]].push_back(prerequisite[0]);;
            indegree[prerequisite[0]]++;
        }

        vector<int> ans = BFS(0,vis,indegree,adj);
        return ans.size()==numCourses;
    }
};