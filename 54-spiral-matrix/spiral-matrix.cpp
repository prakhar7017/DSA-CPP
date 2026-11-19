class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0;
        int down = rows-1;
        int left = 0;
        int right = cols-1;
        int dir=0;
        vector<int>ans;
        while(left<=right && top<=down){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            if(dir==1){
                for(int i=top;i<=down;i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            if(dir==2){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            if(dir==3){
                for(int i=down;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if(dir>3) dir=0;
        }
        return ans;
    }
};