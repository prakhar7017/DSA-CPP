class Solution {
    private:
    void merge(vector<int>& arr, int s, int e) {
        int totalLen=e-s+1;
        int gap=(totalLen/2)+(totalLen%2);
        while(gap>0){
            int i=s;
            int j=s+gap;
            while(j<=e){
                if(arr[i]>arr[j]){
                    swap(arr[i],arr[j]);
                }
                ++i;
                ++j;
            }
            gap= gap<=1 ? 0 : (gap/2)+(gap%2);
        }
    }

    void mergeSort(vector<int>& arr, int s, int e) {

        if (s >= e) {
             return;
        }

        int mid = s + (e - s) / 2;

        mergeSort(arr, s, mid);

        mergeSort(arr, mid + 1, e);

        merge(arr, s, e);

    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        mergeSort(nums,s,e);
        return nums;
    }
};