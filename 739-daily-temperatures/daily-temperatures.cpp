class Solution {
public:
    typedef pair<int,int>P;
    vector<int>solveOptimised(vector<int>& temperatures){
        int n = temperatures.size();
        stack<P>st;
        st.push({temperatures[n-1],n-1});
        vector<int>ans(n,0);
        for(int i = n-2;i>=0;i--){
            int curr = temperatures[i];
            while(!st.empty() && st.top().first <= curr){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top().second - i;
            }
            st.push({curr,i});
        }
        return ans;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        return solveOptimised(temperatures);
    }
};