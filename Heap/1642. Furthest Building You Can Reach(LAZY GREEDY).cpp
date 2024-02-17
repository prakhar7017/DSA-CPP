// i have options to either use bricks or ladders thats why used rescursion to solve. But due to very high constraints cannot be solved using memoization. 

//So, used LAZY GREEDY approach to solve the problem. 

// recursive code with memoization but not working for high constraints
class Solution {
public:
    vector<vector<int>>t;
    int solveUsingRec(vector<int>& heights, int bricks, int ladders,int index,vector<vector<int>>&v
    ){
        // base case
        if(index>=heights.size()-1){
            return 0;
        }

        if(v[bricks][ladders]!=-1){
            return v[bricks][ladders];
        }

        if(heights[index]<heights[index+1]){
            int heightDiff=abs(heights[index]-heights[index+1]);
            int useBricks=0;
            int useLadders=0;
            if(bricks>=heightDiff){
                useBricks=1+solveUsingRec(heights,bricks-heightDiff,ladders,index+1.v);
            }
            if(ladders>0){
                useLadders=1+solveUsingRec(heights,bricks,ladders-1,index+1,v);
            }
            return v[bricks][ladders]=max(useBricks,useLadders);
        }else{
            return v[bricks][ladders]=1+solveUsingRec(heights,bricks,ladders,index+1,v);
        }
        return -1;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int index=0;
        t=vector<vector<int>>(bricks+1,vector<int>(ladders+1,-1));
        return solveUsingRec(heights,bricks,ladders,index,t);
    }
};


// lazy greedy approach
// Lazy greedy" is a term that combines two concepts: "greedy algorithms" and "lazy evaluation."
// Lazy Evaluation:
//This is like procrastinating a bit with your work. You only do things when you absolutely need to.

//Let's say you have a pile of homework. Instead of doing it all at once, you do a little bit whenever you're forced to.

// simply bole toh : "greedly kaam karte jao or jha fhas jao waha par past ma jo glat descision liya tha usko change karte jao, or jab bhi koi naya descision lena ho toh usko bhi change karte jao"

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int>maxi; // to keep track of the maximum height difference jo ki bricks se cover ho sakta hai
        int i=0;
        for(;i<n-1;i++){

            if(heights[i+1]<=heights[i]){ // agar next building ki height kam hai toh simply move to next building
                continue;
            }

            int heightDiff=abs(heights[i+1]-heights[i]); // agar next building ki height jyada hai toh uska height difference nikal liya

            if(bricks>=heightDiff){ // agar bricks se cover ho sakta hai toh simply bricks se cover kar do
                bricks-=heightDiff; // bricks se cover kiya toh bricks kam ho jayenge
                maxi.push(heightDiff); // or us height difference ko max heap mai push kar do
            }else if(ladders>0){ // yha tak poucha iska mtlb bricks se cover nhi ho sakta or ladders bhi hai toh ladders use kar do
                if(!maxi.empty()){ // agar max heap mai kuch hai toh usko use kar do
                    int maxiTop=maxi.top(); // sabsa jada bricks se jo height cover ho sakta hai vo nikal li
                    if(maxiTop>heightDiff){ // abb dekh ki past ma jo maximum bricks use ki thi agar wo yha par use karu toh kya ma bricks se cover kar sakta hu . if yes toh bricks se cover kar do
                        bricks+=maxiTop; // past ma jo maximum bricks use ki thi usko  current bricks ma add kar do
                        maxi.pop(); // or max heap mai se pop kar do
                        bricks-=heightDiff; // fir bricks ma sa current height difference ko subtract kar do
                        maxi.push(heightDiff); // or current height difference ko max heap mai push kar do jo ki current bricks ka usage denote kar rha hh
                        ladders--; // or past ma bricks ko hta kar ladders use kiya hai toh ladders kam ho jayenge
                    }else{ // if no toh ladders use kar do
                        ladders--; // ladders use kiya toh ladders kam ho jayenge
                    }
                }else{
                    ladders--; // agar max heap mai kuch nhi hai toh ladders use kar do
                }
            }else{
                break; // agar bricks se bhi nhi cover ho sakta or ladders bhi nhi hai toh simply break kar do , isse age nhi ja skte hh
            }
        }
        return i;
    }
};