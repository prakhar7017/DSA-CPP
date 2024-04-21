/*
    Row with minimum number of 1's

    Given a 2D binary matrix(1-based indexed) a of dimensions nxm , determine the row that contains the minimum number of 1's.
    Note: The matrix contains only 1's and 0's. Also, if two or more rows contain the minimum number of 1's, the answer is the lowest of those indices.

*/


class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int ans;
        int c=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(a[i][j]==1) ++count;
            }
            if(count<c){
                c=count;
                ans=i;
            }
        }
        return ans+1;
    }
};

time complecity:O(n*m)
space complexity:O(1)