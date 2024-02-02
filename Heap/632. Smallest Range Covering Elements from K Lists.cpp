class Info{
    public:
    int data;
    int rowIndex;
    int colIndex;
    Info(int data,int row,int col):data(data),rowIndex(row),colIndex(col){};
};

class compare{
    public:
    bool operator()(Info* a ,Info* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*,vector<Info*>,compare>pq;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int n=nums.size();
        // first elements of k list push kardeye heap ma
        for(int i=0;i<n;i++){
            int element=nums[i][0];
            int row=i;
            int col=0;
            Info* temp=new Info(element,row,col);
            pq.push(temp);
            maxi=max(maxi,element);
            mini=min(mini,element);
        }
        int startAns=mini;
        int endAns=maxi;
        while(!pq.empty()){
            auto front=pq.top();
            int topData=front->data;
            int topRow=front->rowIndex;
            int topCol=front->colIndex;
            pq.pop();
            mini=topData;
            // maxi mini se ek range hh or ek range startAns or endAns sa hh meko ab choti range mil rhi hh updated maxi and mini sa toh meko startAns or endAnd ko update akrna hh
            if((maxi-mini)<(endAns-startAns)){ // agar choti range mil gyi toh 
                // update
                startAns=mini;
                endAns=maxi;
            }

            // insertion of new element
            if(topCol+1<nums[topRow].size()){ // valid index
                int element=nums[topRow][topCol+1];
                Info* newElement=new Info(element,topRow,topCol+1);
                // very crucial step to update maxi dont frogot
                maxi=max(maxi,element);
                pq.push(newElement);
            }else{
                break; // list ended and i have to break it 
            }
        }
        vector<int>ans;
        ans.push_back(startAns);
        ans.push_back(endAns);
        return ans;
    }
};