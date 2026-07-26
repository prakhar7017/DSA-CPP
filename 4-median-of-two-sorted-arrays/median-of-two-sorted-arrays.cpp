class Solution {
public:
    double bruteForceWithExtraSpace(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> temp(m + n);

        int i = 0;
        int j = 0;
        int k = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                temp[k++] = nums1[i++];
            } else {
                temp[k++] = nums2[j++];
            }
        }

        while (i < n) {
            temp[k++] = nums1[i++];
        }

        while (j < m) {
            temp[k++] = nums2[j++];
        }

        int size = n + m;

        if (size % 2 == 1)
            return temp[size / 2];

        return (temp[size / 2] + temp[(size / 2) - 1]) / 2.0;
    }
    double bruteForceWithNoExtraSpace(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        // vector<int> temp(m + n); no needed

        int size = n + m;

        int idx1 = (size / 2) - 1;
        int element1 = -1;

        int idx2 = (size / 2);
        int element2 = -1;

        int i = 0;
        int j = 0;
        int k = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                if(k == idx1) element1 = nums1[i];
                if(k == idx2) element2 = nums1[i];
                i++;
            } else {
                if(k == idx1) element1 = nums2[j];
                if(k == idx2) element2 = nums2[j];
                j++;
            }
            k++;
        }


        while (i < n) {
            if(k == idx1) element1 = nums1[i];
            if(k == idx2) element2 = nums1[i];
            i++;
            k++;
        }

        while (j < m) {
            if(k == idx1) element1 = nums2[j];
            if(k == idx2) element2 = nums2[j];
            j++;
            k++;
        }

        if (size % 2 == 1)
            return element2;

        return (element2 + element1) / 2.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return bruteForceWithNoExtraSpace(nums1,nums2);
    }
};