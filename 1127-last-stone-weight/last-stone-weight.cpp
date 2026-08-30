class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxH;
        for(int stone:stones) maxH.push(stone);
        while(maxH.size()>1){
            int y = maxH.top(); maxH.pop();
            int x = maxH.top(); maxH.pop();
            if(x!=y) maxH.push(y-x);
        }
        return maxH.empty() ? 0 : maxH.top();
    }
};