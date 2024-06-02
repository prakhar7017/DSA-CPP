/*
    Construct list using given q XOR queries

    Given a list s that initially contains only a single value 0. There will be q queries of the following types:

    0 x: Insert x in the list
    1 x: For every element a in s, replace it with a ^ x. ('^' denotes the bitwise XOR operator)
    Return the sorted list after performing the given q queries.

*/

class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &que) {
        vector<int>ans;
        int XOR=0;
        for(int i=q-1;i>=0;i--){
            if(que[i][0]==0){
                ans.push_back(que[i][1]^XOR);
            }else{
                XOR^=que[i][1];
            }
        }
        ans.push_back(XOR);
        sort(begin(ans),end(ans));
        return ans;
        
    }
};

// time complexity: O(qlogq)
// space complexity: O(q)
