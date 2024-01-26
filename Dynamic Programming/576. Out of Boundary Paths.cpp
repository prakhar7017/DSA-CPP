class Solution {
public:
    int mod=1000000007;
    int v[51][51][51];
    long solve(int m,int n,int maxMove,int st,int sc){
        if(st<0 || st>=m || sc<0 || sc>=n){
            return 1;
        }

        if(maxMove<=0){
            return 0;
        }

        if(v[st][sc][maxMove]!=-1){
            return v[st][sc][maxMove];
        }

        long ans=0;
        ans+=solve(m,n,maxMove-1,st-1,sc);
        ans+=solve(m,n,maxMove-1,st,sc+1);
        ans+=solve(m,n,maxMove-1,st+1,sc);
        ans+=solve(m,n,maxMove-1,st,sc-1);
        return v[st][sc][maxMove]=ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(v,-1,sizeof(v));
        return solve(m,n,maxMove,startRow,startColumn)%mod;
    }
};

// time complxity: O(m*n*maxMove)
// space complexity: O(m*n*maxMove)