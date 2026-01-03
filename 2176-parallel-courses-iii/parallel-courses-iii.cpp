class Solution {
public:
    void topoSort(int n,vector<int>&maxTime,vector<int>&indegree,vector<int>& time,unordered_map<int,vector<int>>&adj){
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
                maxTime[i]= time[i-1];
            }
        }

        while(!q.empty()){
            int currCourse = q.front();
            q.pop();

            for (int &next:adj[currCourse]){
                maxTime[next]=max(maxTime[next],maxTime[currCourse]+time[next-1]);
                indegree[next]--;
                if (indegree[next]==0){
                    q.push(next);
                }
            }
        }
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n+1,0);
        
        for(vector<int>&rel:relations){
            int prev= rel[0];
            int next = rel[1];
            adj[prev].push_back(next);
            indegree[next]++;
        }
        vector<int>maxTime(n+1,0);
        topoSort(n,maxTime,indegree,time,adj);
        int result = 0;
        for(int i=1;i<=n;i++){
            result = max(result,maxTime[i]);
        }
        return result;
    }
};