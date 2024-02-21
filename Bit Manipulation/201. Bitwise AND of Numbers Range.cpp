class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int shiftCount = 0;
        while (left != right)
        {
            left = left >> 1;
            right = right >> 1;
            shiftCount++;
        }
        return left << shiftCount;
    }
};

// time complexity: O(logn)
// space complexity: O(1)

int rangeBitwiseAnd(int left, int right)
{
    while (right > left)
    {
        right = ((right) & (right - 1)); // n & n-1
    }
    return right;
}

// time complexity: O(logn)
// space complexity: O(1)