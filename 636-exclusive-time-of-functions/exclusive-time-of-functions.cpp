class Solution {
public:
    vector<int> solve(int n, vector<string>& logs) {
        stack<int> st;
        int prevTime = 0;
        vector<int> result(n, 0);
        for (string& log : logs) {
            stringstream ss(log);
            string id, type, time;
            getline(ss, id, ':');
            getline(ss, type, ':');
            getline(ss, time, ':');

            int functionId = stoi(id);
            int timestamp = stoi(time);

            if (type == "start") {
                if (!st.empty()) {
                    result[st.top()] += timestamp - prevTime;
                }
                st.push(functionId);
                prevTime = timestamp;
            } else {

                result[st.top()] += timestamp + 1 - prevTime;
                st.pop();
                prevTime = timestamp + 1;
            }
        }
        return result;
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        return solve(n,logs);
    }
};