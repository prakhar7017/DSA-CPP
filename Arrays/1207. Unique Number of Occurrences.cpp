// solution 1: using unordered_map and unordered_set
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto &x:arr){
            mp[x]++;
        }
        unordered_set<int>st;
        for(auto &it:mp){
            if(st.find(it.second)!=st.end()) return false;
            st.insert(it.second);
        }
        return true;
    }
};


// using vector and sorting
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>v(2001,0);
        int n=arr.size();
        for(int i=0;i<n;i++){
            v[arr[i]+1000]++;
        }
        sort(v.begin(),v.end());
        for(int i=1;i<2001;i++){
            if(v[i]!=0 && v[i]==v[i-1]) return false;
        }
        return true;
    }
};

// here the contraints given :
//     1 <= arr.length <= 1000
//     -1000 <= arr[i] <= 1000

// so we can use a vector of size 2001 to store the frequency of each element of the array.
// how it works:
//     if(arr[i])==-1000 and by this  v[arr[i]+1000]++;  we are adding 1000 to -1000 so the result will be 0 . we will use this 0 as a index in v vector;
//     if (arr[i])==-999 and by this  v[arr[i]+1000]++;  we are adding 1000 to -999 so the result will be 1 . we will use this 1 as a index in v vector;
//     if(arr[i])==1000 and by this  v[arr[i]+1000]++;  we are adding 1000 to 1000 so the result will be 2000 . we will use this 2000 as a index in v vector;

// thes index will corresponds to actual numbers and we can track frequency of each number in this way.



//****************************Python Solution************************
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        v=[0]*2001
        for num in arr:
            v[num+1000]+=1

        v.sort()
        for i in range(1,2001):
            if(v[i]!=0 and v[i]==v[i-1]): 
                return False
        
        return True

        

//************************************TypeScript Solution***********************
function uniqueOccurrences(arr: number[]): boolean {
    const v:number[]=new Array(2001).fill(0);
    for(let num of arr){
        v[num+1000]++;
    }

    v.sort((a,b)=>a-b);

    for(let i=1;i<2001;i++){
        if(v[i]!=0 && v[i]==v[i-1]) return false;
    }
    return true;
};