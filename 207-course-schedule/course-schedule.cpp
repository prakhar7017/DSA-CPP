class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int>ans;
        for (vector<int>& prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(int &v:adj[curr]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }

        return ans.size()==numCourses;


    }
};