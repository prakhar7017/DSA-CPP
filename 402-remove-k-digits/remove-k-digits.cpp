class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()==k) return "0"; // means sare number delete ho jayege toh empty string bachegi
        string ans=""; // string will act as a stack
        int n=num.length();
        for(int i=0;i<n;i++){
            while(ans.length()>0 && ans.back()>num[i] && k>0){ // if num[i] mere ans ke back sa bada hh tab tak htate raho ans.back ko . but make sure k>0 hona chye
                ans.pop_back();
                --k;
            }
            if(ans.length() > 0 || num[i]!='0'){ // making sure that preceding zeros na japye result ma 
            // agar mera answer ki length >0 hh ya phir ane wala num[i] !=0 tabhi push karuga 
            // mtlb agar result ki length already zero hh or num[i] ==0 hua toh descard it 
                ans.push_back(num[i]);
            }
        }

        // if for cases like 1111 or 1234 where numbers already in correct order,
        // in that case k will reamin as it is
        // so delete last k elemets , for forming smallest no

        while(ans.length()>0 && k>0 ){
            ans.pop_back();
            --k;
        }
        if(ans=="") return "0";

        return ans;
    }
};