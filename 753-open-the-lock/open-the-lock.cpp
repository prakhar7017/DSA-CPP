class Solution {
public:
    void fillNeighbour(string &curr,queue<string>&q,unordered_set<string>&st){
        for(int i=0;i<4;i++){
            char ch=curr[i];

            char inc = ch == '9' ? '0' : ch+1 ;
            char desc = ch == '0' ? '9' : ch-1;

            curr[i]=inc;
            if(st.find(curr)==st.end()) {
                st.insert(curr);
                q.push(curr);
            }

            curr[i]=desc;
            if(st.find(curr)==st.end()) {
                st.insert(curr);
                q.push(curr);
            }

            curr[i] = ch;
        }
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(begin(deadends),end(deadends));
        string start="0000";
        if(st.find(start)!=st.end()) return -1;
        queue<string>q;
        // initial State
        q.push(start);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string frontString=q.front();
                q.pop();

                if(frontString==target) return level;

                fillNeighbour(frontString,q,st);
            }
            // one level has been processed
            // inc the level
            ++level;
        }
        return -1;
    }
};