class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficint=0;
        int balance=0;

        int s=0;
        for(int i=0;i<gas.size();i++){
            balance=balance+gas[i]-cost[i];

            if(balance<0){
                deficint+=abs(balance);
                s=i+1;
                balance=0;
            }
        }
        if(balance-deficint>=0){
            return s;
        }else{
            return -1;
        }
    }
};

// time complexity: O(n)
