
// using Dijkstra 
class Solution {
public:
    vector<vector<int>>directions{{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>>dist(rows+1,vector<int>(cols+1,INT_MAX));

        if(rows==0 || cols==0 || grid[0][0]==1){
            return -1;
        }

        auto isSafe=[&](int newX,int newY){
            return newX>=0 && newX<rows && newY>=0 && newY<cols;
        };

        set<pair<int,pair<int,int>>>st;

        st.insert({0,{0,0}});
        grid[0][0]=1;
        dist[0][0]=0;

        while(!st.empty()){
            auto topElement=st.begin();
            auto topPair=*topElement;
            int srcDist=topPair.first;
            pair<int,int>srcCorr=topPair.second;
            int x=srcCorr.first;
            int y=srcCorr.second;
            st.erase(st.begin());

            for(vector<int>&dir:directions){
                int new_x=x+dir[0];
                int new_y=y+dir[1];

                int nbrDist=1;
                if(isSafe(new_x,new_y) && grid[new_x][new_y]==0){

                    if(srcDist+nbrDist<dist[new_x][new_y]){
                        auto prevEntry=st.find({dist[new_x][new_y],{new_x,new_y}});
                        if(prevEntry!=st.end()){
                            st.erase(prevEntry);
                        }
                        dist[new_x][new_y]=srcDist+nbrDist;
                        grid[new_x][new_y]=1;
                        st.insert({dist[new_x][new_y],{new_x,new_y}});
                    }
                }
            }
        }
        if(dist[rows-1][cols-1]==INT_MAX){
            return -1;
        }
        return dist[rows-1][cols-1]+1;
    }
};
// time complexity: O(n^2)
// space complexity: O(n^2)


// using BFS 
// why BFS is working here, because each edge has same weight.
class Solution {
public:
    vector<vector<int>>directions{{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        if(rows==0 || cols==0 || grid[0][0]==1){
            return -1;
        }

        auto isSafe=[&](int newX,int newY){
            return newX>=0 && newX<rows && newY>=0 && newY<cols;
        };

        queue<pair<int,int>>q;
        int level=0;

        q.push({0,0});
        grid[0][0]=1;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                pair<int,int> frontPair=q.front();
                q.pop();
                int x=frontPair.first;
                int y=frontPair.second;

                if(x==rows-1 && y==cols-1){
                    return level+1;
                }

                for(vector<int> dir:directions){
                    int new_x=x+dir[0];
                    int new_y=y+dir[1];

                    if(isSafe(new_x,new_y) && grid[new_x][new_y]==0){
                        q.push({new_x,new_y});
                        grid[new_x][new_y]=1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

// time comeplexity: O(n^2)
// space complexity: O(n^2)
