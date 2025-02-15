class Solution {
public:
    bool check(int index,int currSum,string s,int &target,vector<vector<int>>&v){
        if(index==s.length()) {
            if(currSum==target) return true;
            else return false;
        }
        if(currSum > target) return false;

        if(v[index][currSum]!=-1) return v[index][currSum];


        bool possible=false;
        for(int j=index;j<s.length();j++){
            string sub=s.substr(index,j-index+1);
            int val=stoi(sub);
            possible=possible || check(j+1,currSum+val,s,target,v);

            if(possible==true) return true;
        }
        return v[index][currSum]=possible;
    }
    int punishmentNumber(int n) {
        int punish=0;
        for(int num=1;num<=n;num++){
            int sq=num*num;
            string s=to_string(sq);
            vector<vector<int>>v(s.length(),vector<int>(num+1,-1));
            if(check(0,0,s,num,v)){
                punish+=sq;
            }
        }
        return punish;
    }
};