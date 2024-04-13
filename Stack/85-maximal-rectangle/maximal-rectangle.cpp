class Solution {
public:
    vector<int> getNSR(vector<int>&heights){ // next smaller element to the right
        int n=heights.size();
        stack<int>st;
        vector<int>NSR(n);
        for(int i=n-1;i>=0;i--){ // right to left
            if(st.empty()){
                NSR[i]=n; // if stack is empty, then there is no smaller element to the right
            }else{
                while(!st.empty() && heights[st.top()]>=heights[i]){ // pop until we find a smaller element
                    st.pop();
                }
                if(st.empty()){ // if stack is empty, then there is no smaller element to the right
                    NSR[i]=n;
                }else{ // if stack is not empty, then the top element is the next smaller element to the right
                    NSR[i]=st.top();
                }
              
            }
            st.push(i); // push the current element
        }
        return NSR;
    }
    vector<int> getNSL(vector<int>&heights){ // next smaller element to the left
        int n=heights.size();
        stack<int>st;
        vector<int>NSL(n);
        for(int i=0;i<n;i++){ // left to right
            if(st.empty()){ // if stack is empty, then there is no smaller element to the left
                NSL[i]=-1;
            }else{
                while(!st.empty() && heights[st.top()]>=heights[i]){ // pop until we find a smaller element
                    st.pop();
                }
                if(st.empty()){ // if stack is empty, then there is no smaller element to the left
                    NSL[i]=-1;
                }else{
                    NSL[i]=st.top(); // if stack is not empty, then the top element is the next smaller element to the left
                }
            }
            st.push(i); // push the current element
        }
        return NSL;
    }
    int findMaxArea(vector<int>&heights){
        // width[i] = NSR[i]-NSL[i]-1

        vector<int>NSR=getNSR(heights);
        vector<int>NSL=getNSL(heights);

        int n=heights.size();
        vector<int>width(n);
        for(int i=0;i<n;i++){ // calculate the width of the rectangle
            width[i]=NSR[i]-NSL[i]-1;
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            int area=width[i]*heights[i]; // calculate the area of the rectangle
            maxArea=max(maxArea,area);
        }
        return maxArea; // return the maximum area
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<int>heights(cols);

        // add the first row in the height 1d-arr
        for(int col=0;col<cols;col++){
            heights[col]=matrix[0][col]=='1' ? 1:0;
        }

        int maxArea=findMaxArea(heights);

        // add further 1 to n-1 rows
        for(int row=1;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(matrix[row][col]=='0'){
                    heights[col]=0;
                }else{
                    heights[col]+=1;
                }
            }
            // after adding one row
            maxArea=max(maxArea,findMaxArea(heights));
        }
        return maxArea;
    }
};