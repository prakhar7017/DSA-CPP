// using single arrays as map
class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.length();
        int arr[26]={0};

        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(arr[i]>0){
                ans+=arr[i];
            }
        }
        return ans;
    }
};
// using two arrays as map
class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.length();
        int arrS[26]={0};
        int arrT[26]={0};

        for(int i=0;i<n;i++){
            arrS[s[i]-'a']++;
            arrT[t[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(arrS[i]>arrT[i]){
                ans+=arrS[i]-arrT[i];
            }
        }
        return ans;
    }
};