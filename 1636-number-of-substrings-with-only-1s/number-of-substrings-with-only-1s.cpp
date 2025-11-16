class Solution {
public:
    const int MOD = 1e9+7;
    int solve1(string s){
        long long result = 0;
        long long count1 = 0;

        for (char& ch : s) {
            if (ch == '1') {
                count1++;
            } else {
                result = (result + count1*(count1+1)/2)%MOD;
                count1=0;
            }
        }
        result = (result + count1*(count1+1)/2)%MOD;

        return result;
    }
    int solve2(string s){
        long long result = 0;
        long long count1 = 0;

        for (char& ch : s) {
            if (ch == '1') {
                count1++;
                result= (result + count1)%MOD;
            } else {
                count1=0;
            }
        }
        return result;
    }
    int numSub(string s) {
        return solve1(s);
    }
};