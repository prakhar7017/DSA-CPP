/*
 Party of Couples
 You are given an integer array arr[] of size n, representing n number of people in a party, each person is denoted by an integer. Couples are represented by the same number ie: two people have the same integer value, it means they are a couple. Find out the only single person in the party of couples.

NOTE: It is guarantee that there exist only one single person in the party.
*/

class Solution{
    public:
    int findSingle(int n, int arr[]){
        int ans=0;
        for(int i=0;i<n;i++){
            ans^=arr[i];
        }
        return ans;
    }
};

// time complexity : O(n)
// space complexity : O(1)

// link : https://www.geeksforgeeks.org/problems/alone-in-couple5507/1 