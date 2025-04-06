class Solution {
public:
    bool solveUsingBFS(int &numCourses, vector<vector<int>>& prerequisites){
        vector<int>indeg(numCourses,0);
        queue<int>q;
        unordered_map<int,vector<int>>adjList;
        int count=0;
        for(vector<int>&prereq:prerequisites){
            int course1=prereq[0];
            int course2=prereq[1];
            adjList[course2].push_back(course1);
            indeg[course1]++;
        }

        // for(int course=0;course<numCourses;course++){
        //     for(int cor:adjList[course]){
        //         indeg[cor]++;
        //     }
        // }

        for(int course=0;course<numCourses;course++){
            if(indeg[course]==0){
                q.push(course);
                count++;
            }
        }

        while(!q.empty()){
            int frontCourse=q.front();
            q.pop();
            for(int &course:adjList[frontCourse]){
                indeg[course]--;
                if(indeg[course]==0){
                    q.push(course);
                    count++;
                }
            }
        }

        if(count==numCourses) return true;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return solveUsingBFS(numCourses,prerequisites);
    }
};