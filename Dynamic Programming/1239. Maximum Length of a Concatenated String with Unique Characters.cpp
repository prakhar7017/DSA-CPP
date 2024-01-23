class Solution {
public:
    unordered_map<string,int>mp;
    bool isDublicate(string s1,string s2){
        int arr[26]={0};
        for(char &ch:s1){
            // handleing case like "aa"
            if(arr[ch-'a']>0){
                return true;
            }
            arr[ch-'a']++;
        }

        for(char &ch:s2){
            if(arr[ch-'a']>0){
                return true;
            }
        }
        return false;
    }
    int solve(vector<string>&arr,string temp,int i,int &n){
        // base case
        if(i>=n) return temp.length();

        int include=0;
        int exclude=0;

        if(mp.find(temp)!=mp.end()){
            return mp[temp];
        }
        if(isDublicate(arr[i],temp)){
            exclude=solve(arr,temp,i+1,n);
        }else{
            include=solve(arr,temp+arr[i],i+1,n);
            exclude=solve(arr,temp,i+1,n);
        }
        return mp[temp]=max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        int index=0;
        int n=arr.size();
        string temp="";
        mp.clear();
        return solve(arr,temp,index,n);
    }
};

