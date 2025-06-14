class Solution {
public:
    // bool hasDuplicate(string &s1,string &s2){
    //     int arr[26]={0};
    //     for(char &ch:s1){
    //         if(arr[ch-'a']>0) return true;
    //         arr[ch-'a']++;
    //     }

    //     for(char &ch:s2){
    //         if(arr[ch-'a']>0) return true;
    //         arr[ch-'a']++;
    //     }

    //     return false;
    // }
    // int solve(int index,string temp,vector<string>&arr,unordered_map<string,int>&mp){
    //     if(index>=arr.size()) return temp.length();
    //     if(mp.find(temp)!=mp.end()){
    //         return mp[temp]; 
    //     }
    //     int include=0;
    //     int exclude=0;
    //     if(hasDuplicate(arr[index],temp)){
    //         // exclude
    //         exclude=solve(index+1,temp,arr,mp);
    //     }else{
    //         include=solve(index+1,temp+arr[index],arr,mp);
    //         exclude=solve(index+1,temp,arr,mp);
    //     }
    //     return mp[temp]=max(include,exclude);

    // }
    void solve(int index,int temp,int &result,vector<int>&uniqueChar){
        result=max(result,__builtin_popcount(temp));
        for(int idx=index;idx<uniqueChar.size();idx++){
            if((temp & uniqueChar[idx])==0){
                solve(idx+1,temp|uniqueChar[idx],result,uniqueChar);
            }
        }
    }
    int maxLength(vector<string>& arr) {
        // string temp="";
        // unordered_map<string,int>mp;
        // return solve(0,temp,arr,mp);

        vector<int>uniqueChar;

        for(string &s:arr){
            unordered_set<char> st(begin(s),end(s));
            if(st.size()!=s.length()) continue; // has duplicates.

            int val=0;
            for(char &ch:s){
                val=(val | (1 << (ch-'a')));
            }
            uniqueChar.push_back(val);
        }
        int result=0;
        int temp=0;
        solve(0,temp,result,uniqueChar);
        return result;
    }
};