#include <iostream>
#include <vector>
using namespace std;

void findCombinations(vector<int>& nums, vector<int> data, int index, int r, vector<vector<int>>& ans) {

  //base case
  if (data.size() == r) {
    ans.push_back(data);
    return;
  }
  
  if (index >= nums.size()) {
    return;
  }
  
  //processing // recursive calls
  data.push_back(nums[index]);
  findCombinations(nums, data, index + 1, r, ans);
  
  data.pop_back();
  findCombinations(nums, data, index + 1, r, ans);
}

int main() {
  vector<vector<int>> ans; 
  vector<int> nums = {1, 2, 3, 4, 5};
  int r = 3;
  vector<int> data;
  findCombinations(nums, data, 0, r, ans);

  for (auto i : ans) {
    for (int num : i) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}

output->
1 2 3 
1 2 4 
1 2 5 
1 3 4 
1 3 5 
1 4 5 
2 3 4 
2 3 5 
2 4 5 
3 4 5 