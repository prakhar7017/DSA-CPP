class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        
        int l=0; // this pointer will point jha ma 0 wale elements ko rakh skta hu .
        int idx=0; // this pointer will iterate through the array and will help in swapping the elements to its correct position.
        int r=n-1; // this pointer will point jha ma 2 wale elements ko rakh skta hu .
        
        while(idx<=r){
            if(nums[idx]==0){ // agar idx wala element 0 h toh usko left ma rakhna hoga.
                swap(nums[idx++],nums[l++]); // yha idx++ isliye kiya h kyuki idx wala element 0 h toh usko left ma rakhne ke baad hume idx ko bhi aage badhana hoga.
            }else if(nums[idx]==2){ // agar idx wala element 2 h toh usko right ma rakhna hoga.
                swap(nums[idx],nums[r--]); // yha galti karuga . right sa jab koi swap hoke idx ki position par ayega toh ma sure nhi hu ki kya ayega wo 0/1/2 kuch bhi askata hh isley yha par idx ko badha nhi raha hu. jisse ma igli iteration ma usse check kar saku or usko sehi postion par bhej saku
            }else{
                ++idx; // agar idx wala element 0 h or 2 h toh usko bich ma hi rakhna hoga.
            }
        }

    }
};

// time complexity:O(n)
// space complexity:O(1)