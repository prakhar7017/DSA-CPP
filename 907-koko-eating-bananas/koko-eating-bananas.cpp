class Solution {
public:
    bool canEatAll(vector<int>& piles,int perHr,int h){
        int actualHrs = 0;
        for(int &bananas:piles){
            actualHrs+=bananas/perHr;

            if(bananas%perHr!=0){
                actualHrs++;
            }

            if (actualHrs > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r = *max_element(begin(piles),end(piles));

        while(l<r){
            int perHr = l + (r-l)/2;

            if(canEatAll(piles,perHr,h)){
                r = perHr;
            }else {
                l = perHr+1;
            }
        }
        return r;
    }
};