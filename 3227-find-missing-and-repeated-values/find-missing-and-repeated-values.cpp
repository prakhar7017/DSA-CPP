class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int missing =-1, repeat=-1;
        unordered_map<int,int>freq;
        for(vector<int>&col: grid){
            for(int num:col) freq[num]++;
        }

        for(int num=1;num<=n*n;num++){
            if(!freq.count(num)) missing=num;
            else if(freq[num]==2) repeat=num;
        }

        return {repeat,missing};
    }
};