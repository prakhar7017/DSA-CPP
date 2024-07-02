class Solution {
public:
    bool solveUsingKansAlgo(int &numCourses,vector<int>&indegree,unordered_map<int,list<int>>&adjList){
        queue<int>q;
        vector<int>topo;

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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        unordered_map<int,list<int>>adjList;

        for(vector<int>&vec:prerequisites){
            int u=vec[1];
            int v=vec[0];
            indegree[v]++;
            adjList[u].push_back(v);
        }

        bool ans=solveUsingKansAlgo(numCourses,indegree,adjList);

        return ans;
    }
};