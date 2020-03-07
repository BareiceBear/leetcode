/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

class Solution {
public:      
    using ivec = vector<int>;
    using ivec2D = vector<ivec>;
   
    void combinationSum2(int num, int target, ivec candidates, ivec &combination, ivec2D &combinations)
    {         
        if(0 == target)
        {
            combinations.push_back(combination);
            return;
        }
        
        if(target < 0)
            return;
        
        for(int i = num; i < candidates.size(); ++i)
        {
            if(i > num && candidates[i - 1] == candidates[i])
                continue;
                
            combination.push_back(candidates[i]);
            combinationSum2(i + 1, target - candidates[i], candidates, combination, combinations);
            combination.pop_back();
        }
        
        return;
    }
    

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        ivec2D combinations;
        ivec combination;

        combinationSum2(0, target, candidates, combination, combinations);
        return combinations;
    }
};

bool comp(int a, int b)
{
    return a < b;
}

class Solution {
public:      
    using ivec = vector<int>;
    using ivec2D = vector<ivec>;
    using iimap = map<int, int>;
   
    void combinationSum2(int num, int target, iimap maps, ivec &combination, ivec2D &combinations)
    { 
        if(0 > target)
            return;
        
        if(0 == target)
        {
            combinations.push_back(combination);
            return;
        }
        
        auto it = maps.begin();
        for(int i = 0; i < num; ++i)
            it++;
        
        for(it; it != maps.end(); ++it)
        {
            if(it->second <= 0)
                continue;
            
            it->second--;
            target -= it->first;
            combination.push_back(it->first);
            combinationSum2(distance(maps.begin(), it), target, maps, combination, combinations);
            combination.pop_back();
            target += it->first;
            it->second++;
        }
        
        return;
    }
    

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        ivec2D combinations;
        ivec combination;
        iimap maps;
        
        for(int i : candidates)
        {
            if(maps.end() == maps.find(i))
                maps[i] = 0;
            maps[i]++;
        }
        
        combinationSum2(0, target, maps, combination, combinations);
        return combinations;
    }
};
