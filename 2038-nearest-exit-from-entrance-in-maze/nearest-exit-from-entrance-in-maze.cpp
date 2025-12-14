class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    bool isSafe(int x,int y,vector<vector<char>>& maze){
        if(x>=0 && x<maze.size() && y>=0 && y<maze[0].size() && maze[x][y]!='+') return true;
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();

        queue<P> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int steps = 0;
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize--) {
                P temp = q.front();
                int currX = temp.first;
                int currY = temp.second;
                q.pop();

                if (temp != make_pair(entrance[0], entrance[1]) &&
                    (currX == 0 || currX == rows - 1 || currY == 0 ||
                     currY == cols - 1))
                    return steps;

                for(vector<int>&dir:directions){
                    int newX=currX+dir[0];
                    int newY=currY+dir[1];
                    if(isSafe(newX,newY,maze)){
                        q.push({newX,newY});
                        maze[newX][newY]='+';
                    }
                }    
            }
            steps++;
        }
        return -1;
    }
};