class Solution {
public:
    int BFS(vector<string>& deadends, string target){
        unordered_set<string>st(begin(deadends),end(deadends));
        if(st.count("0000")) return -1;
        if(target == "0000") return 0;
        st.insert("0000");
        queue<string>q;
        q.push("0000");

        int steps=0;
        while(!q.empty()){
            int size = q.size();
            steps++;
            while(size--){
                string curr = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    char ori = curr[i];
                    curr[i]=(ori-'0'+1)%10+'0';
                    if(!st.count(curr)){
                        if(curr == target) return steps;
                        q.push(curr);
                        st.insert(curr);
                    }

                    curr[i]=(ori-'0'+9)%10+'0';
                    if(!st.count(curr)){
                        if(curr == target) return steps;
                        q.push(curr);
                        st.insert(curr);
                    }
                    curr[i]=ori;
                } 
            }
        }
        return -1;
    }
    int openLock(vector<string>& deadends, string target) {
        return BFS(deadends,target);
    }
};