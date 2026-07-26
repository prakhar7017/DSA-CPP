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
    double optimisedBinarySearch(vector<int>& nums1, vector<int>& nums2){
        if(nums1.size()>nums2.size()) return optimisedBinarySearch(nums2,nums1);

        int m = nums1.size();
        int n = nums2.size();

        int s = 0;
        int e = m;

        while(s<=e){
            int Px = s + (e-s)/2;
            int Py = (m+n+1)/2 - Px;

            // left half
            int x1 = (Px == 0) ? INT_MIN: nums1[Px-1];
            int x2 = (Py == 0) ? INT_MIN: nums2[Py-1];
            int x3 = (Px == m) ? INT_MAX: nums1[Px];
            int x4 = (Py == n) ? INT_MAX: nums2[Py];

            if(x1<=x4 && x2<=x3) {
                if((m+n)%2 == 1) return max(x1,x2);
                return (max(x1,x2) + min(x3,x4))/2.0;
            }
            
            if(x1>x4){
                e = Px - 1;
            }else{
                s = Px + 1;
            }
        }
        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return optimisedBinarySearch(nums1,nums2);
    }
};