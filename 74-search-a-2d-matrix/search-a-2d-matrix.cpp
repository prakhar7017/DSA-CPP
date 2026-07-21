class Solution {
public:
    bool binarySearch(vector<int>&nums,int target){
        int s = 0;
        int e = nums.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]<target) s = mid+1;
            else e = mid - 1;
        }
        return false;
    }
    bool solveBruteForce(vector<vector<int>>& matrix, int target){
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i=0;i<rows;i++){
            if(matrix[i][0]<=target && matrix[i][cols-1]>=target){
                if(binarySearch(matrix[i],target)) return true;
                break;
            }
        }
        return false;
    }
    bool solveOptimised(vector<vector<int>>& matrix, int target){
        int rows = matrix.size();
        int cols = matrix[0].size();
        int s = 0;
        int e = rows-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(matrix[mid][0]>target) e = mid-1;
            else if(matrix[mid][cols-1]<target) s = mid + 1;
            else return binarySearch(matrix[mid], target); 
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return solveOptimised(matrix,target);
    }
};