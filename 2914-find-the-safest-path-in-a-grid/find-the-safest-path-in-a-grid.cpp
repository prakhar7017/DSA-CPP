class Solution {
public:
    int n;
    vector<vector<int>>directions{{-1,0},{0,1},{1,0},{0,-1}};

    bool check(vector<vector<int>>&nearDisFromTheaf,int sf){
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        if(nearDisFromTheaf[0][0]<sf){
            return false;
        }
        q.push({0,0});
        vis[0][0]=true;

        while(!q.empty()){
            int currI=q.front().first;
            int currJ=q.front().second;
            q.pop();
            if(currI==n-1 && currJ==n-1){
                return true;
            }
            for(vector<int>&dir:directions){
                int newI=currI+dir[0];
                int newJ=currJ+dir[1];

                if(newI>=0 && newI<n && newJ>=0 && newJ<n && !vis[newI][newJ]){
                    if(nearDisFromTheaf[newI][newJ]>=sf){
                        q.push({newI,newJ});
                        vis[newI][newJ]=true;
                    }
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<int>>nearDisFromTheaf(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(n,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }   

        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int currI=q.front().first;
                int currJ=q.front().second;
                q.pop();
                nearDisFromTheaf[currI][currJ]=level;
                for(vector<int>&dir:directions){
                    int newI=currI+dir[0];
                    int newJ=currJ+dir[1];
                    if(newI>=0 && newI<n && newJ>=0 && newJ<n && !vis[newI][newJ]){
                        q.push({newI,newJ});
                        vis[newI][newJ]=true;
                    }
                }
            }
            ++level;
        }

        int s=1;
        int e=400;
        int ans=0;
        while(s<=e){
            int sf=s+(e-s)/2;
            if(check(nearDisFromTheaf,sf)){
                ans=sf;
                s=sf+1;
            }else{
                e=sf-1;
            }
        }

        return ans;

    }
};