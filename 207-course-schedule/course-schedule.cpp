class Solution {
public:
    bool solveUsingKansAlgo(int &numCourses,vector<int>&indegree,unordered_map<int,list<int>>&adjList){
        queue<int>q;
        vector<int>topo;
        vector<bool>vis(numCourses,false);
        stack<int>st;

        for(int course=0;course<numCourses;course++){
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

        return topo.size()==numCourses;

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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        unordered_map<int,list<int>>adjList;
        vector<bool>vis(numCourses,false);
        vector<bool>dfsCalls(numCourses,false);
        stack<int>st;

        for(vector<int>&vec:prerequisites){
            int u=vec[1];
            int v=vec[0];
            indegree[v]++;
            adjList[u].push_back(v);
        }

        bool ans=false;
        // bool ans=solveUsingKansAlgo(numCourses,indegree,adjList);

        for(int course=0;course<numCourses;course++){
            if(!vis[course]){
                solveUsingDFS(course,st,vis,dfsCalls,adjList);
            }
        }
        vector<int>result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        if(result.size()==numCourses){
            return true;
        }
        return false;
    }
};