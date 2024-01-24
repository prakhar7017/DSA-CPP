class Solution{
    public:
    void heapify(vector<int>&ans,int n,int i){
        int leftIndex=2*i+1;
        int rightIndex=2*i+2;
        int largest=i;
        if(leftIndex<n && ans[largest]<ans[leftIndex]){
            largest=leftIndex;
        }
        if(rightIndex<n && ans[largest]<ans[rightIndex]){
            largest=rightIndex;
        }
        if(i!=largest){
            swap(ans[i],ans[largest]);
            i=largest;
            heapify(ans,n,i);
        }
    }
    void buildHeap(vector<int>&ans){
        int n=ans.size();
        int pos=(n>>1)-1; // n/2-1
        for(int i=pos;i>=0;--i){
            heapify(ans,n,i);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int>ans;
        ans.insert(ans.end(),a.begin(),a.end()); // insert all elements of a in ans in one go.
        
        ans.insert(ans.end(),b.begin(),b.end());
        
        buildHeap(ans);
        
        return ans;
    }
};