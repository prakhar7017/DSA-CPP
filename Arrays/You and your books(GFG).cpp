/*
    You and your books
    You have n stacks of books. Each stack of books has some nonzero height arr[i] equal to the number of books on that stack ( considering all the books are identical and each book has a height of 1 unit ). In one move, you can select any number of consecutive stacks of books such that the height of each selected stack of books arr[i] <= k. Once such a sequence of stacks is chosen, You can collect any number of books from the chosen sequence of stacks.
    What is the maximum number of books that you can collect this way?

*/

class Solution {
  public:
    typedef long long ll;
    long long max_Books(int arr[], int n, int k) {
        ll maxBooks=0;
        ll size=0;
        for(int i=0;i<n;i++){
            int num=arr[i];
            if(num<=k){
                size+=num;
                maxBooks=max(maxBooks,size);
            }else{
                size=0;
            }
        }
        return maxBooks;
    }
};

// time complexity:O(n)
// space complexity:O(1)