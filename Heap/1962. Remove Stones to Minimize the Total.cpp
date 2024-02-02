class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int n=piles.size();
        for(int i=0;i<n;i++){
            int element=piles[i];
            pq.push(element);
        }
        while(k!=0){
            int topElement=pq.top();
            pq.pop();
            topElement=(topElement)-(topElement/2);
            pq.push(topElement);
            k--;
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};

// time complexity is O(nlogn) 
// space complexity is O(n)