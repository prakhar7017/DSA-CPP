/*
1249. Minimum Remove to Make Valid Parentheses

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.

*/

// using stack
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        unordered_set<int>set;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                if(st.empty()){
                    set.insert(i);
                }else{
                    st.pop();
                }
            }
        }


        while(!st.empty()){
            set.insert(st.top());
            st.pop();
        }

        string ans="";

        for(int i=0;i<n;i++){
            if(set.find(i)==set.end()){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

// time complexity is O(n)
// space complexity is O(n)

//----------------------------------------------------------------------------------

// without using stack
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        string ans="";
        int open=0; // to keep track of open brackets

        // first we will remove all the extra closing brackets, while goig L->R
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){ // if it is a character
                ans.push_back(s[i]); // ans ma push kardo character
            }else if(s[i]=='('){ // open bracket aya hh
                ++open; // open ko increment kardo
                ans.push_back(s[i]); // ans ma push kardo
            }else if(open > 0){ // yha par close bracket aya hh , usse phele check ki open bracket h ya nhi, open >  0 mtlb open bracket h. if open bracket ==0 mtlb open bracket nhi h.
                --open; // open ko decrement kardo , kuki wo closing bracket sa match ho gya h
                ans.push_back(s[i]); //ans ma push kardo
            }
        }

        // now we will remove all the extra opening brackets, while going R->L
        int close =0; // to keep track of closing brackets
        int n1=ans.length();
        string finalAns=""; // final answer
        for(int i=n1-1;i>=0;i--){ 
            if(ans[i]>='a' && ans[i]<='z'){ // if it is a character
                finalAns.push_back(ans[i]); // ans ma push kardo character
            }else if(ans[i]==')'){ // close bracket aya hh , to close ko increment kardo
                ++close;
                finalAns.push_back(ans[i]); //  ans ma push kardo
            }else if(close > 0 ) { // yha par open bracket aya hh , usse phele check ki close bracket h ya nhi, close >  0 mtlb close bracket h. if close bracket ==0 mtlb close bracket nhi h.
                --close; // close ko decrement kardo , kuki wo open bracket sa match ho gya h
                finalAns.push_back(ans[i]); //ans ma push kardo
            }
        }
        reverse(begin(finalAns),end(finalAns)); // reverse the final answer
        return finalAns;
    }
};

// time complexity is O(n)
// space complexity is O(n)