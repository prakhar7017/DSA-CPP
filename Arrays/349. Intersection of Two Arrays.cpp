class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1(nums1.begin(),nums1.end());
        unordered_set<int>st2;

        for(int &num:nums2){
            if(st1.find(num)!=st1.end()){
                st2.insert(num);
            }
        }
        vector<int>ans(st2.begin(),st2.end());
        return ans;
    }
};
// time complexity: O(n+m)
// space complexity: O(n+m)


//--------------------------------------------------------------------------



class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1(nums1.begin(),nums1.end());
        vector<int>ans;

        for(int &num:nums2){
            if(st1.find(num)!=st1.end()){
                ans.push_back(num);
                st1.erase(num);
            }
        }
        return ans;
    }
};

// time complexity: O(n+m)
// space complexity: O(n)


//--------------------------------------------------------------------------


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        unordered_set<int>st1;

        for(int &num:nums2){
            if(binary_search(nums1.begin(),nums1.end(),num)){
                st1.insert(num);
            }
        }
        vector<int>ans(st1.begin(),st1.end());
        return ans;
    }
};

// time complexity: O(nlogn+mlogn)
// space complexity: O(n)


//--------------------------------------------------------------------------

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        vector<int>ans;
        while(i<nums1.size() && j<nums2.size()){

            while(i<nums1.size()-1 && nums1[i]==nums1[i+1]) ++i; // to avoid duplicates
            while(j<nums2.size()-1 && nums2[j]==nums2[j+1]) ++j; // to avoid duplicates

            if(nums1[i]==nums2[j]) {
                ans.push_back(nums1[i]);
                ++i;
                ++j;
            }
            else if(nums1[i]<nums2[j]) ++i;
            else if(nums2[j]<nums1[i]) ++j;
        }
        return ans;
    }
};

// time complexity: O(n+m)
// space complexity: O(n) 