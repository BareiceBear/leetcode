/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

class Solution {
public:
    void combination(int num, int target, vector<int>& candidates, vector<int> &tmp, vector<vector<int>> &combinations)
    {
        if(0 == target)
        {
            combinations.push_back(tmp);
            return;
        }
        
        for(int i = num; i < candidates.size(); ++i)
        {
            target -= candidates[i];
            if(0 > target)
                return;
            
            tmp.push_back(candidates[i]);
            combination(i, target, candidates, tmp, combinations);
            tmp.pop_back();
            target += candidates[i];
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> combinations;
        vector<int> tmp;
        int sum = 0, num = 0;
        
        combination(0, target, candidates, tmp, combinations);
     
        return combinations;
    }
};
