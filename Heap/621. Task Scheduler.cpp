class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freqArr(26);
        for(char &ch:tasks){
            freqArr[ch-'A']++;
        }

        priority_queue<int>pq; // max heap 
        //we want to finish the process which is most occurring (having highest frequency)
        //so that we don't have to finish in the last with p gaps.

        for(int i=0;i<26;i++){
            if(freqArr[i]>0){
                pq.push(freqArr[i]);
            }
        }

        int time=0;

        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){ // we have to take n+1 tasks in each cycle 
                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    --freq; // decreasing the frequency of the task
                    temp.push_back(freq);
                }
            }

            for(int f:temp){ // updating the heap
                if(f>0) pq.push(f);
            }

            if(pq.empty()){// if pq is empty then we don't need to add n+1 gaps
                time+=temp.size();
            }else{ // if pq is not empty then we need to add n+1 gaps
                time+=n+1;
            }
        }
        return time;
    }
};

// time complexity : o(nlogn)
// space complexity: o(1)
