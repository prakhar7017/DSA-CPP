/*
    The main idea is to divide these two unique numbers into different groups so that they can be identified separately. Here's a step-by-step explanation:

    XOR All Numbers:
    First, you take the XOR of all the numbers in the array. This operation will cancel out all the numbers that appear twice, leaving you with the XOR of the two unique numbers (let's call them a and 𝑏).

    Find a Distinguishing Bit:
    Next, you find a bit that is different between 𝑎 and 𝑏 . You do this by taking the XOR result from the previous step and isolating the rightmost bit that is '1'. This bit will be different between 𝑎 and 𝑏 .

    Divide Numbers into Two Groups:
    Then, you use the distinguishing bit to divide all the numbers into two groups. One group will contain numbers where this bit is '1', and the other group will contain numbers where this bit is '0'.

    XOR Each Group:
    Finally, you XOR all the numbers within each group separately. Since all the pairs of numbers (that appear twice) will cancel each other out, you will be left with one unique number in each group.
    The result will be the two unique numbers you were looking for. This method efficiently separates the two unique numbers by leveraging the properties of the XOR operation and bit manipulation.
    
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long XOR = 0;
        for(int num:nums){
            XOR^=num;
        }

        int mask=(XOR)&(-XOR); 

        int groupA=0;
        int groupB=0;

        for(int num:nums){
            if(num&mask){
                groupA^=num;
            }else{
                groupB^=num;
            }
        }

        return {groupA,groupB};
    }
};