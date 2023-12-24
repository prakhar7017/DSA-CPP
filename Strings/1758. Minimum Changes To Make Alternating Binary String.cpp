// Approach 1:
class Solution {
public:
    int minOperations(string s) {
        int st_0=0;
        int st_1=0;
        int i=0;
        while(i<s.length()){
            if(i&1==1){ // odd index
                if(s[i]=='1'){ //010101
                    st_1++;
                }else{
                    st_0++;
                }
            }else{ // even index
                if(s[i]=='1'){
                    st_0++;
                }else{
                    st_1++;
                }
            }
            i++;
        }
        return min(st_0,st_1);
    }
};

// time complexity: O(n);

// Approach 2:
int minOperations(string s) {
        int st_0=0; // 01010101
        int i=0;
        while(i<s.length()){
            if((i&1)==1){ // odd index
                if(s[i]=='0'){
                    st_0++;
                }
            }else{ // even index
                if(s[i]=='1'){
                    st_0++;
                }
            }
            i++;
        }
        int st_1=s.length()-st_0; //10101010
        return min(st_0,st_1);
}