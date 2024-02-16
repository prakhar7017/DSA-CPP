class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(auto &it:arr){
            mp[it]++;
        }
        vector<int>v;
        for(auto &it:mp){
            v.push_back(it.second);
        }

        sort(begin(v),end(v));

        for(int i=0;i<v.size();i++){
            k-=v[i];
            if(k<0){
                return v.size()-i;
            }
        }
        return 0;
    }
};

// time complexity is O(nlogn)
// space complexity is O(n)

//*****************************************************************************
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(auto &it:arr){
            mp[it]++;
        }

        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &it:mp){
            pq.push(it.second);
        }

        while(!pq.empty()){
            k-=pq.top();
            if(k<0){
                return pq.size();
            }
            pq.pop();
        }
        return 0;
    }
};

// time complexity is O(nlogn) 
// space complexity is O(n)

//*********************************************************************************

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp; // [element->freq]
        for(auto &it:arr){
            mp[it]++;
        }

        int uniqueTypes=mp.size();
        vector<int>v(n+1);

        for(auto &it:mp){ 
            //   0, 1 , 2 , 3 , 4   index->freq   
            // [                  ] types of elment jinki freq equal to index hh 
            int freq=it.second;
            v[freq]++;
        }

        for(int freq=1;freq<v.size();freq++){
            int typesIcanDelete=min(k/freq,v[freq]);  // min(expected,reality) means ma kitne types ko delter kar skta hu or kitne mere pass availabele hh 
            k=k-(typesIcanDelete*freq); // k- (type * its freq)->total no of elments
            uniqueTypes-=typesIcanDelete;
            if(k<=freq){
                return uniqueTypes;
            }
        }

        return 0;


    }
};

// time complexity is O(n)
// space complexity is O(n)