class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=0;
            }else{
                ans[i]=st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};


//************************Python Code*********************************
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n=len(temperatures)
        ans=[0]*n
        st=[]
        for i in range(n):
            while st and temperatures[i]>temperatures[st[-1]]:
                prev_idex=st.pop()
                ans[prev_idex] = i - prev_idex

            st.append(i)

        return ans
        


//************************TypescriptCode*********************************
function dailyTemperatures(temperatures: number[]): number[] {
     const n: number = temperatures.length;
        const st: number[] = [];
        const ans: number[] = new Array(n).fill(0);

        for (let i = n - 1; i >= 0; i--) {
            while (st.length > 0 && temperatures[i] >= temperatures[st[st.length - 1]]) {
                st.pop();
            }
            if (st.length === 0) {
                ans[i] = 0;
            } else {
                ans[i] = st[st.length - 1] - i;
            }
            st.push(i);
        }

        return ans;
};