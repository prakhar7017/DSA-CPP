/*  
    Xoring and Clearing

    You are given an array arr[] of size n. You need to do the following:

    You need to calculate the bitwise XOR of each element in the array with its corresponding index (indices start from 0).
    After step1, print the array.
    Now, set all the elements of arr[] to zero.
    Now, print arr[].
*/

class Solution {
  public:
    void printArr(int n, int arr[]) {
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void setToZero(int n, int arr[]) {
        // Use memset to set arr to zero
        memset(arr,0,n*sizeof(arr[0]));
    }

    void xor1ToN(int n, int arr[]) {
        for(int i=0;i<n;i++){
            arr[i]=arr[i]^i;
        }
    }
};

// time complexity: O(n)
// space complexity: O(1)


/*
void* memset(void* ptr, int value, size_t num);

memset is a function in C and C++ used to fill a block of memory with a particular value. Here's the prototype of the memset function

ptr is a pointer to the block of memory to fill.
value is the value to be set. It's passed as an int, but it's commonly used with unsigned char values to represent bytes.
num is the number of bytes to be set to the value.


n * sizeof(arr[0]): This is the number of bytes you want to set. It's calculated as n (the number of elements you want to initialize) multiplied by sizeof(arr[0]), which gives you the size of one element in the array arr.

sizeof(arr[0]) gives the size of one element in the array. It's a common technique used to make the code more flexible and avoid hardcoding the size of the elements.
Here's what happens step by step:

sizeof(arr[0]) gives the size of one element in the array. Let's say sizeof(arr[0]) is 4 bytes, and n is 10. So, n * sizeof(arr[0]) gives 10 * 4 = 40 bytes.

memset then fills the memory block pointed to by arr with 0 for 40 bytes, effectively initializing the array arr with zeros.

*/