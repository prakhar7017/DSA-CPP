class Solution {
public:
    vector<int> topoSort(int numCourses, vector<vector<int>>& prerequisites){
        vector<int>indegree(numCourses,0);
        unordered_map<int,vector<int>>adj;
        queue<int>q;
        vector<int>ans;

        for(vector<int>&preq:prerequisites){
            adj[preq[1]].push_back(preq[0]);
            indegree[preq[0]]++;
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int currNode= q.front();
            q.pop();
            ans.push_back(currNode);

            for(int &v:adj[currNode]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }

        return ans.size()==numCourses ? ans: vector<int>();
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        return topoSort(numCourses,prerequisites);
    }
};