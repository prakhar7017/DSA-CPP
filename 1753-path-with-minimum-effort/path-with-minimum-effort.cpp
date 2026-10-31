class Solution {
public:
    typedef pair<int,pair<int,int>>P; // {diff,{x,y}}
    vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
    int n;
    int m;
    bool isSafe(int x,int y){
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        result[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int diff = pq.top().first;
            int x    = pq.top().second.first;
            int y    = pq.top().second.second;
            pq.pop();


            if(x==n-1 && y==m-1) return diff;

            for(vector<int>&dir:directions){
                int newX = x + dir[0];
                int newY = y + dir[1];

                if(isSafe(newX,newY)){
                    int absDiff = abs(heights[x][y]-heights[newX][newY]);
                    int maxDiff = max(diff,absDiff);

                    if(result[newX][newY]>maxDiff){
                        result[newX][newY]=maxDiff;
                        pq.push({maxDiff,{newX,newY}});
                    }
                }
            }
        }
        return result[n-1][m-1];
    }
};