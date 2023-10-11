class Solution{
    private:
    vector<bool>Sieve(long long int n){
        vector<bool>sieve(n+1,true);
        sieve[0]=sieve[1]=false;
        for(long long int i=2;i<=sqrt(n);i++){
            if(sieve[i]){
                long long int j=i*i;
                while(j<=n){
                    sieve[j]=false;
                    j+=i;
                }
            }
        }
        return sieve;
    }
    vector<bool>SegmentedSieve(long long int L, long long int R){
        vector<bool>primes=Sieve(sqrt(R));
        vector<long long int>basePrimes;
        for(long long int i=0;i<primes.size();i++){
            if(primes[i]){
                basePrimes.push_back(i);
            }
        }
        
        vector<bool>segSieve(R-L+1,true);
        
        if(L==1){
            segSieve[0]=false;
        }
        
        for(auto prime:basePrimes){
            long long int fm=(L/prime)*prime;
            fm=fm<L ? fm+prime : fm;
            long long int j=max(fm,prime*prime);
            while(j<=R){
                segSieve[j-L]=false;
                j+=prime;
            }
        }
        return segSieve;
    }
public:
    #define M 1000000007
    long long primeProduct(long long L, long long R){
        vector<bool>ss=SegmentedSieve(L,R);
        long long int ans=1;
        for(int i=0;i<ss.size();i++){
            if(ss[i]){
                long long int primeNumber=(i+L) % M;
                ans=(ans*primeNumber)%M;
            }
        }
        return ans;
    }
};

// time complexity: O(nlog(logn)) 