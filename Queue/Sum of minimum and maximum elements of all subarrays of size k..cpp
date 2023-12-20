#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int sumMaxMinSlidingWindow(vector<int>&nums,int &k){
    int ans=0;
    deque<int>dq1,dq2;
    
    // process first window
    for(int i=0;i<k;i++){
        int element=nums[i];
        
        // for max 
        while(!dq1.empty() && element>=nums[dq1.back()]){
            dq1.pop_back();
        }
        
        // for min 
        while(!dq2.empty() && element<=nums[dq2.back()]){
            dq2.pop_back();
        }
        
        dq1.push_back(i);
        dq2.push_back(i);
    }
    
    // process next windows
        // store ans 
        // removal 
        // addition
    
    for(int i=k;i<nums.size();i++){
        ans+=nums[dq1.front()]+nums[dq2.front()];
        
        // removal of out of index
        if(!dq1.empty() && i-dq1.front()>=k){
            dq1.pop_front();
        }
        if(!dq2.empty() && i-dq2.front()>=k){
            dq2.pop_front();
        }
        
        // removal of chote elements for dq1 and removal of bade elemets for dq2
        int element=nums[i];
        while(!dq1.empty() && element>=nums[dq1.back()]){
            dq1.pop_back();
        }
        while(!dq2.empty() && element<=nums[dq2.back()]){
            dq2.pop_back();
        }
        
        dq1.push_back(i);
        dq2.push_back(i);
    }
    
    // process last windows
    ans+=nums[dq1.front()]+nums[dq2.front()];
    
    return ans;
}
int main() {
    vector<int>nums={3, 1, 4, 2, 6, 8, 5};
    int k=3;
    int ans=sumMaxMinSlidingWindow(nums,k);
    cout<<"sum is : "<<ans<<endl;
	return 0;
}