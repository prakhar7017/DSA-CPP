/*
    Three way partitioning
    
    Given an array of size n and a range [a, b]. The task is to partition the array around the range such that the array is divided into three parts.
    1) All elements smaller than a come first.
    2) All elements in range a to b come next.
    3) All elements greater than b appear in the end.
    The individual elements of three sets can appear in any order. You are required to return the modified array.

    Note: The generated output is 1 if you modify the given array successfully.
*/

// three pointer approach
class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        int n=arr.size();
        
        int l=0; // this pointer will point jha ma less than a wale elements ko rakh skta hu .
        int idx=0; // this pointer will iterate through the array and will help in swapping the elements to its correct position.
        int r=n-1; // this pointer will point jha ma b se badi value wale elements ko rakh skta hu .

        // jab ma a sa chote elements jo left ma rkah dunga or b sa bade elements ko right ma rakh dunga toh obviously jo bich ma bachega vo a se b ke beech wale elements honge.
        
        while(idx<=r){ // yha idx<=r isliye kiya h kyuki jab idx==r hoga toh us time pe bhi hume swap karna padega kyuki idx==r hoga toh us time pe bhi hume check karna padega ki arr[idx] b se bada h ya nhi.
            if(arr[idx]<a){ // agar idx wala element a se chota h toh usko left ma rakhna hoga.
                swap(arr[idx++],arr[l++]); // yha idx++ isliye kiya h kyuki idx wala element a se chota h toh usko left ma rakhne ke baad hume idx ko bhi aage badhana hoga.
            }else if(arr[idx]>b){ // agar idx wala element b se bada h toh usko right ma rakhna hoga.
                swap(arr[idx],arr[r--]); // yha galti karuga. right sa jab koi swap hoke idx ki position par ayega toh ma sure nhi hu ki kya ayega wo 0/1/2 kuch bhi askata hh isley yha par idx ko badha nhi raha hu. jisse ma igli iteration ma usse check kar saku or usko sehi postion par bhej saku
            }else{
                ++idx; // agar idx wala element a se bada h or b se chota h toh usko bich ma hi rakhna hoga.
            }
        }
    }
};

// time complexity:O(n)
// space complexity:O(1)