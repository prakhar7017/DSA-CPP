class Solution {
public:
    string reorganizeString(string s) {
        int hash[26]={0};

        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
        }

        char max_c;
        int max_f=INT_MIN;

        for(int i=0;i<26;i++){
            if(hash[i]>max_f){
                max_f=hash[i];
                max_c=i+'a';
            }
        }

        int index=0;
        while(max_f>0 && index<s.size()){
            s[index]=max_c;
            max_f--;
            index+=2;
        }

        if(max_f!=0){
            return "";
        }

        hash[max_c-'a']=0;
        
        for(int i=0;i<26;i++){
            while(hash[i]!=0){
                index=index>=s.size() ? 1 : index;
                s[index]=i+'a';
                hash[i]--;
                index+=2;
            }
        }
        return s;
    }
};

// time complexity: O(n)  n is the length of the string  