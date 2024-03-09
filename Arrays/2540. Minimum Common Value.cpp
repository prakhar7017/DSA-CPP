
// Possible Solution but not optimal, Gives TLE for large inputs
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int common=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            int freqCount=count(nums2.begin(),nums2.end(),nums1[i]);
            if(freqCount>0) common=min(common,nums1[i]);
        }
        return common==INT_MAX ? -1 : common;
    }
};
// time complexity: O(n*m)
// space complexity: O(1)

// using binary search
class Solution {
public:
    bool bs(int s,int e,int target,vector<int>&nums){
        while(s<=e){
            int mid=s+((e-s)>>1);
            if(nums[mid]==target) return true;
            else if(nums[mid]<target) s=mid+1;
            else e=mid-1;
        }
        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int common=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            bool isPresent=bs(0,nums2.size()-1,nums1[i],nums2);
            if(isPresent) common=min(common,nums1[i]);
        }
        return common == INT_MAX ? -1 : common; 
    }
};
// time complexity: O(nlogm)
// space complexity: O(1)


// stl of binary search
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int common=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            bool isPresent=binary_search(nums2.begin(),nums2.end(),nums1[i]);
            if(isPresent) common=min(common,nums1[i]);
        }
        return common == INT_MAX ? -1 : common; 
    }
};

// using unordered_set
// unordered set gives element search in O(1) time complexity
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st(nums2.begin(),nums2.end());
        for(int i=0;i<nums1.size();i++){
            if(st.find(nums1[i])!=st.end()){
                return nums1[i];
            }
        }
        return -1;
    }
};


// most optimal solution
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]) return nums1[i];
            else if(nums1[i]<nums2[j]) ++i;
            else if(nums2[j]<nums1[i]) ++j;
        }
        return -1;
    }
};

//worst case time complexity: O(n+m) // n and m are the sizes of the two arrays
//space complexity: O(1)