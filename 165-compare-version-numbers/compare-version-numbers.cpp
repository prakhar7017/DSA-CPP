class Solution {
public:
    vector<string> getVersionSepratedByDot(string &version){
        stringstream ss(version);
        string token="";
        vector<string>versions;
        while(getline(ss,token,'.')){
            versions.push_back(token);
        }
        return versions;
    }
    int compareVersion(string version1, string version2) {
        vector<string>versions1=getVersionSepratedByDot(version1);
        vector<string>versions2=getVersionSepratedByDot(version2);
        int i=0;
        int j=0;
        while(i<versions1.size() || j<versions2.size()){
            int v1= i<versions1.size() ? stoi(versions1[i]) : 0;
            int v2= j<versions2.size() ? stoi(versions2[j]) : 0;

            if(v1<v2){
                return -1;
            }else if(v1>v2){
                return 1;
            }else{
                ++i;
                ++j;
            }
        }
        return 0;

    }
};