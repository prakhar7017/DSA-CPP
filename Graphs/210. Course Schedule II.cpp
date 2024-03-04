class Solution {
public:
    void prepareAdj(vector<vector<int>>& prerequisites,unordered_map<int,list<int>>&adjList){
        for(vector<int>i:prerequisites){
            int u=i[0];
            int v=i[1];
            adjList[v].push_back(u);
        }
    }
    vector<int> topoSort(int numCourse,unordered_map<int,list<int>>&adjList,vector<int>&topOrder){
        queue<int>q;
        unordered_map<int,int>inDegree;
        for(int node=0;node<numCourse;node++){
            for(auto nbr:adjList[node]){
                inDegree[nbr]++;
            }
        }
        for(int node=0;node<numCourse;node++){
            if(inDegree[node]==0){
                q.push(node);
            }
        }
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            topOrder.push_back(frontNode);
            for(auto nbr:adjList[frontNode]){
                inDegree[nbr]--;
                
                //check for zero
                if(inDegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        return topOrder;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adjList;
        prepareAdj(prerequisites,adjList);
        vector<int>topOrder;
        topoSort(numCourses,adjList,topOrder);
        if(topOrder.size()==numCourses) return topOrder;
        return {};
    }
};