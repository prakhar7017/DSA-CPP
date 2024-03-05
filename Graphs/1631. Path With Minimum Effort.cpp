class Solution {
public:
    bool isSafe(int newX,int newY,int currX,int currY,int row,int col,vector<vector<int>>&diff){
        if(newX>=0 && newX<row && newY>=0 && newY<col && diff[currX][currY]<diff[newX][newY]){
            return true;
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& h) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>mini; //{diff,{xCor,Ycor}}
        int row=h.size();
        int col=h[0].size();
        vector<vector<int>>diff(row,vector<int>(col,INT_MAX));
        int destX=row-1;
        int destY=col-1;
        // initial State Maintain
        diff[0][0]=0;
        mini.push({0,{0,0}});
        while(!mini.empty()){
            pair<int,pair<int,int>>topNode=mini.top();
            mini.pop();
            int currDiff=topNode.first;
            pair<int,int> currCor=topNode.second;
            int currX=currCor.first;
            int currY=currCor.second;
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            // check all nbr
            for(int i=0;i<4;i++){
                int newX=currX+dx[i];
                int newY=currY+dy[i];
                if(isSafe(newX,newY,currX,currY,row,col,diff)){
                    int maxDiff=max(currDiff,abs(h[currX][currY]-h[newX][newY]));
                    diff[newX][newY]=min(diff[newX][newY],maxDiff);
                    if(newX!=destX || newY!=destY){
                        mini.push({diff[newX][newY],{newX,newY}});
                    }
                }
            }
        }
        return diff[destX][destY];
    }
};