class Solution {
public:
    string solve(string& path) {
        stringstream ss(path);
        string token = "";
        stack<string> st;
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".")
                continue;
            if (token != "..") {
                st.push(token);
            } else if (!st.empty()) {
                st.pop();
            }
        }
        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        return result.empty() ? "/" : result;
    }
    string simplifyPath(string path) {return solve(path);}
};