class Solution {
public:
    int bruteForce(vector<int>& stones){
        while(stones.size()>1){ //n
            sort(begin(stones),end(stones)); //nlogn
            int a = stones.back(); 
            stones.pop_back();
            int b = stones.back();
            stones.pop_back();

            stones.push_back(abs(a-b));
        }
        return stones.back();
    }
    // timecomleixty: n*2logn
    int solveOptimised(vector<int>& stones){
        priority_queue<int>pq;
        for(int &stone:stones){
            pq.push(stone);
        }
        while(pq.size()>1){ //n
            int a = pq.top(); 
            pq.pop();
            int b = pq.top();
            pq.pop();

            pq.push(abs(a-b));
        }
        return pq.top();
    }
    int lastStoneWeight(vector<int>& stones) {
        return solveOptimised(stones);
    }
};