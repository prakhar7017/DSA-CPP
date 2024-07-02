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
    void solveUsingDFS(int course,stack<int>&st,vector<bool>&vis,vector<bool>&dfsCalls,unordered_map<int,list<int>>&adjList){
        vis[course]=true;
        dfsCalls[course]=true;
        for(int &nbrCourse:adjList[course]){
            if(dfsCalls[nbrCourse]==true){
                return;
            }
            if(!vis[nbrCourse]){
                solveUsingDFS(nbrCourse,st,vis,dfsCalls,adjList);
            }
        }
        dfsCalls[course]=false;
        st.push(course);
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

        // vector<int>topo=solveUsingKansAlgo(n,indegree,adjList);
        for(int course=0;course<n;course++){
            if(!vis[course]){
                solveUsingDFS(course,st,vis,dfsCalls,adjList);
            }
        }
        vector<int>topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }

        if(topo.size()==n){
            return topo;
        }
        return {};

    }
};