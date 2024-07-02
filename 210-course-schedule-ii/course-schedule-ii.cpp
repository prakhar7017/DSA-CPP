class Solution {
public:
    vector<int> solveUsingKansAlgo(int &n,vector<int>&indegree,unordered_map<int,list<int>>&adjList){
        queue<int>q;
        vector<int>topo;
        stack<int>st;

        for(int course=0;course<n;course++){
            if(indegree[course]==0){
                q.push(course);
            }
        }

        while(!q.empty()){
            int frontCourse=q.front();
            q.pop();
            topo.push_back(frontCourse);

            for(int &nbrCourse:adjList[frontCourse]){
                indegree[nbrCourse]--;
                if(indegree[nbrCourse]==0){
                    q.push(nbrCourse);
                }
            }
        }

        return topo;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>indegree(n,0);
        unordered_map<int,list<int>>adjList;
        vector<bool>vis(n,false);
        vector<bool>dfsCalls(n,false);
        stack<int>st;

        for(vector<int>&vec:prerequisites){
            int u=vec[1];
            int v=vec[0];
            indegree[v]++;
            adjList[u].push_back(v);
        }

        vector<int>topo=solveUsingKansAlgo(n,indegree,adjList);

        if(topo.size()==n){
            return topo;
        }
        return {};

    }
};