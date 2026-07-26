class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>temp(m+n);

        int i=0;
        int j=0;
        int k=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                temp[k++] = nums1[i++];
            }else{
                temp[k++] = nums2[j++];
            }
        }

        while(i<n){
            temp[k++]=nums1[i++];
        }

        while(j<m){
            temp[k++]=nums2[j++];
        }

        int size = n+m;

        if(size%2==1) return temp[size/2];

        return (temp[size/2] + temp[(size/2)-1])/2.0;
    }
};