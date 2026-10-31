class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int top =0;
        int down = rows-1;
        int left =0;
        int right= cols-1;
        vector<int>ans;
        int dir = 0;
        // dir : 0 = [top][left->right]
        // dir : 1 = [top->bottom][right]
        // dir : 2 = [down][right->left]
        // dir : 3 = [down->top][left] 
        while(top<=down && left<=right){
            if(dir == 0){
                // left to right
                // constant: top
                for(int i=left;i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            if(dir == 1){
                // top to down
                // constant: right
                for(int i=top;i<=down;i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            if(dir == 2){
                // right to left
                // constant: down
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            if(dir == 3){
                // down to top
                // constant: left
                for(int i=down;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if(dir>3) dir = 0;
        }
        return ans;
    }
};