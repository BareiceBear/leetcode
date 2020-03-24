/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/

//though it works, it's too slow
class Solution {
public:
    using ivec = vector<int>;
    void dfs(int from, int depth, int &target, vector<bool> &used, ivec &nums, ivec &tmp, ivec &ret)
    {
        if(0 == target)
            return;
        
        if(depth == nums.size())
        {
            target--;
            if(0 == target)
                ret = tmp;
            return;
        }
        
        for(int i = from; i < nums.size(); ++i)
        {
            if(0 == target)
                return;

            if(used[i])
                continue;
            
            used[i] = true;
            tmp.push_back(nums[i]);
            dfs(0, depth + 1, target, used, nums, tmp, ret);
            tmp.pop_back();
            used[i] = false;
        }
    }
    
    string getPermutation(int n, int k) {
        vector<bool> used(n, false);
        vector<int> nums;
        for(int i = 0; i < n; ++i)
            nums.push_back(i + 1);
        
        int mean = 1;
        for(int i = n - 1; i > 1; --i)
            mean *= i;
        
        int init = k / mean;
        if(init > 0)
        {
             k = k - (init - 1) * mean;
             init -= 1;
        }   
        
        vector<int> tmp;
        vector<int> ret;
        dfs(init, 0, k, used, nums, tmp, ret);
        
        int sum = 0;
        for(int i = 0; i < ret.size(); ++i)
            sum = sum * 10 + ret[i];
        
        return to_string(sum);
    }
};
