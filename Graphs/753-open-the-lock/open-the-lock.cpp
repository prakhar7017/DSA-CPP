/*

    Pattern Recogination :
    1. ask about number or words
    2. Each digit or character can be changed
    3. You have to reach a target
    4. List of word/numbers that are allowed not allowed

    Solution : BFS
    WHY BFS ? 
    we have to go from one state to another state and we have to find the shortest path. Each state can be imagined as node and we have to find the shortest path from start to target. So, BFS is the best approach to find the shortest path in unweighted graph.
*/

class Solution {
public:
    void fillNeighbour(string &curr,queue<string>&q,unordered_set<string>&st){
        for(int i=0;i<4;i++){
            char ch=curr[i];

            char inc = ch == '9' ? '0' : ch+1 ; // increment the digit
            char desc = ch == '0' ? '9' : ch-1; // decrement the digit

            curr[i]=inc;
            if(st.find(curr)==st.end()) { // if not found in deadends
                st.insert(curr); // insert in deadends , so that we dont visit it again
                q.push(curr); // push in queue
            }

            curr[i]=desc;
            if(st.find(curr)==st.end()) { // if not found in deadends
                st.insert(curr);  // insert in deadends , so that we dont visit it again
                q.push(curr); // push in queue
            }

            curr[i] = ch; // revert back the digit to original aka backtracking
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

                if(frontString==target) return level; // target found

                fillNeighbour(frontString,q,st); // create all possible neighbours
            }
            // one level has been processed
            // inc the level
            ++level;
        }
        return -1;
    }
};

//time complexity : (4^10) 
//space complexity : O(4^10) // for storing all possible states