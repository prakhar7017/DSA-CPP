class Solution {
public:
    int countPrimes(int n) {
        if(n==0) return 0;
        vector<bool>sieve(n,true);
        sieve[0]=sieve[1]=false;
        int count=0;
        for(int i=2;i<n;i++){
            if(sieve[i]){
                count++;
                int j=2*i;
                while(j<n){
                    sieve[j]=false;
                    j+=i;
                }
            }
        }
        return count;
    }
};

// sieve of eratosthenes
// time complexity: O(nloglogn) 