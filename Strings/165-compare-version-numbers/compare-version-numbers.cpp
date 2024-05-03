class Solution {
public:
    vector<string> getVersionSepratedByDot(string &version){
        stringstream ss(version); // Used for breaking word
        string token=""; // use to store each word
        vector<string>versions;
        while(getline(ss,token,'.')){ // Tokenize the string on the basis of '.'
            versions.push_back(token); // Store the token in the vector
        }
        return versions;
    }
    vector<string> breakingByDot(string &version){
        vector<string> versions;
        string token="";
        char deli='.';
        for(char s:version){
            cout<<"s "<<s<<endl;
            if(s!=deli){
                token+=s;
            }else{
                versions.push_back(token);
                token.clear();
            }
        }
        if(token.length()!=0){
            versions.push_back(token);
        }
        return versions;
    }
    int compareVersion(string version1, string version2) {
        vector<string>versions1=breakingByDot(version1);

        vector<string>versions2=breakingByDot(version2);
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

// time complexity: O(n)
// space complexity: 0(n)
