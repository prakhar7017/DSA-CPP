// My solution
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,pair<int,int>>mp;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])!=mp.end()){
                pair<int,int>&element=mp[s[i]] ;
                element.second=i;
            }else{
                mp[s[i]]=make_pair(i,i);
            }
        }

        int maxL=0;
        for(auto it:mp){
            pair<int,int>temp=it.second;
            int length=abs(temp.second-temp.first);
            maxL=max(maxL,length);
        }
        return maxL-1;
    }
};

// Better solution
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.length();
        vector<int>v(26,-1);
        int result=-1;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(v[ch-'a']==-1){
                v[ch-'a']=i;
            }else{
                result=max(result,i-v[ch-'a']-1);
            }
        }
        return result;
    }
};