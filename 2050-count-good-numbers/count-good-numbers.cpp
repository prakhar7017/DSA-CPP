class Solution {
public:
    const int Mod=1e9+7;
    int findPower(long long a,long long b){
        if(b==0) return 1;

        long long half=findPower(a,b/2);
        long long result=(half*half) % Mod;
        if(b%2==1){
            result=(a*result)%Mod;
        }
        return result;

    }
    int countGoodNumbers(long long n) {
        long long noOfEvenIndices=(n+1)/2;
        long long noOfOddIndices=n/2;
        return (long long)findPower(5,noOfEvenIndices)*findPower(4,noOfOddIndices)%Mod;

    }
};