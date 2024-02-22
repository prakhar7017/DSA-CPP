class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>count(n+1);
        for(auto t:trust){
            int u=t[0];
            int v=t[1];

            // u trust on v , so v will get 1 more trust and u will lose 1 trust
            count[u]--;
            count[v]++;
        }

        for(int i=1;i<=n;i++){
            if(count[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};

// Find Celebrity Problem Similar
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>M(n+1,vector<int>(n+1,0));
        for(auto t:trust){
            int u=t[0];
            int v=t[1];

            M[u][v]=1;
        }

        stack<int>st;
        for(int i=1;i<=n;i++){
            st.push(i);
        }
        while(st.size()!=1){
            int a=st.top(); 
            st.pop();
            int b=st.top();
            st.pop();

            if(M[a][b]){
                // then a is not judge, discard a
                st.push(b);
            }else{
                // b is not a judge, dicard b
                st.push(a);
            }
        }

        int mighbeJudge=st.top();
        st.pop();

        for(int col=1;col<=n;col++){
            if(M[mighbeJudge][col]!=0){
                return -1;
            }
        }

        for(int row=1;row<=n;row++){
            if(M[row][mighbeJudge]!=1 && row!=mighbeJudge){
                return -1;
            }
        }
        return mighbeJudge;
    }
};

// time complexity: O(n)
// space complexity: O(n)