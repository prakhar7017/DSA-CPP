class Solution {
public:
    bool hasDuplicate(string &s1,string &s2){
        int arr[26]={0};
        for(char &ch:s1){
            if(arr[ch-'a']>0) return true;
            arr[ch-'a']++;
        }

        for(char &ch:s2){
            if(arr[ch-'a']>0) return true;
            arr[ch-'a']++;
        }

        return false;
    }
    int solve(int index,string temp,vector<string>&arr,unordered_map<string,int>&mp){
        if(index>=arr.size()) return temp.length();
        if(mp.find(temp)!=mp.end()){
            return mp[temp]; 
        }
        int include=0;
        int exclude=0;
        if(hasDuplicate(arr[index],temp)){
            // exclude
            exclude=solve(index+1,temp,arr,mp);
        }else{
            include=solve(index+1,temp+arr[index],arr,mp);
            exclude=solve(index+1,temp,arr,mp);
        }
        return mp[temp]=max(include,exclude);

    }
    int maxLength(vector<string>& arr) {
        string temp="";
        unordered_map<string,int>mp;
        return solve(0,temp,arr,mp);
    }
};