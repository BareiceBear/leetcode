class Solution:  
    def mapSolution(self, depth: int, nums: dict, permutation: List[int], permutations: List[List[int]]):
        if depth <= 0:
            permutations.append(copy.deepcopy(permutation))
            return    
        for key in nums:
            if nums[key] <= 0:
                continue
            nums[key] -= 1
            permutation.append(key)
            self.mapSolution(depth - 1, nums, permutation, permutations)
            permutation.pop()
            nums[key] += 1
    
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        permutations = []
        permutation = []

        dictNums = {}
        for num in nums:
            if num in dictNums:
                dictNums[num] += 1
            else:
                dictNums[num] = 1;
        
        self.mapSolution(len(nums), dictNums, permutation, permutations)
        return permutations
