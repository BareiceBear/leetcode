/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<bool> used(nums.size(), false);
        vector<int> path;
        
        if(0 == nums.size())
            return permutations;
        
        dfs(0, nums, used, path, permutations);
        return permutations;
    }
    
protected:
    void dfs(int depth, vector<int>& nums, vector<bool> &used, vector<int> &path, vector<vector<int>> &permutations)
    {
        if(depth == nums.size())
        {
            permutations.push_back(path);
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(!used[i])
            {
                used[i] = true;
                path.push_back(nums[i]);
                dfs(depth + 1, nums, used, path, permutations);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};
