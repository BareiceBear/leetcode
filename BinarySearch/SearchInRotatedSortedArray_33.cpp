/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(0 == nums.size())
            return -1;
        
        int Rrotate = 0;
        int Lrotate = nums.size();
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            if(nums[i + 1] < nums[i])
            {
                Lrotate = i + 1;
                break;
            }
        }
        Rrotate = nums.size() - Lrotate;
        
        int left = 0;
        int right = nums.size() - 1;
        while(right >= left)
        {
            int mid = (left + right) / 2;
            int midNum = 0;
            if(mid < Rrotate)
                midNum = nums[mid + Lrotate];
            else
                midNum = nums[mid - Rrotate];
            
            if(midNum < target)
            {
                left = mid + 1;
            }
            else if(midNum > target)
            {
                right = mid - 1;
            }
            else
                return mid < Rrotate ? mid + Lrotate : mid - Rrotate;
        }
        
        return -1;
    }
};
