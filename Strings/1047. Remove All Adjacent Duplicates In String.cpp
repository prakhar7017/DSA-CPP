class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        int i=0;
        while(i<s.length()){
            if(ans.length()>0 && ans[ans.length()-1]==s[i]){
                ans.pop_back();
            }else{
                ans.push_back(s[i]);
            }
            i++;
        }
        return ans;
    }
};

// time complexity:O(n)

// using stack 

class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        stack<char>st;
        for(auto ch:s){
            if(!st.empty() && st.top()==ch){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        while(!st.empty()){
            char ch=st.top();
            st.pop();
            ans+=ch;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// time compelxity: O(n)

