class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalBottels=numBottles;
        while(numBottles>=numExchange){
            totalBottels+=numBottles/numExchange;
            numBottles=(numBottles/numExchange)+(numBottles%numExchange);
        }
        return totalBottels;

    }
};