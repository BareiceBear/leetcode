/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

class Solution {  
protected:
    void dfs(int depth, vector<bool> &used, vector<int> &nums, vector<int> &permutation, vector<vector<int>> &permutations)
    {
        if(depth >= nums.size())
        {
            permutations.push_back(permutation);
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(used[i])
                continue;
            
            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
            
            used[i] = true;
            permutation.push_back(nums[i]);
            dfs(depth + 1, used, nums, permutation, permutations);
            used[i] = false;
            permutation.pop_back();
        }
        
        return;
    }

public: 
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> permutations;
        vector<int> permutation;
        int depth = 0;
        vector<bool> used(nums.size(), false);
        
        std::sort(nums.begin(), nums.end());
        dfs(depth, used, nums, permutation, permutations);
        return permutations;
    }
};
