class Solution {
    private:
    void reverseStack(stack<string>&st,string& ans){
        //base case
        if(st.empty()){
            return;
        }
        string temp=st.top();
        st.pop();
        reverseStack(st,ans);
        ans+=temp;
    }
public:
    string simplifyPath(string path) {
        stack<string>st;
        int i=0;
        while(i<path.size()){
            int start=i;
            int end=start+1;
            while(end<path.size() && path[end]!='/'){
                end++;
            }
            string minPath=path.substr(start,end-start);
            i=end;
            if( minPath =="/" || minPath=="/."){
                continue;
            }
            if(minPath!="/.."){
                st.push(minPath);
            }else if(!st.empty()){
                st.pop();
            }
        }
        string ans=st.empty() ? "/":"";
        reverseStack(st,ans);
        return ans;

    }
};