/* 
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
] 
*/
//想法1：想利用三维数组来存储每一种结果，然后把为零的那部分抽出来，但是貌似时间复杂度和空间复杂度都比较高，而且三维数组...怎么实现...想了半天没想明白...遂放弃
//想法2：看了题解，固定一个数，然后再做另外两个数的Twosum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int> > sumarr;
        for(int i = 0; i < nums.size(); i++)
        {
          for(int j = i + 1; j < nums.size(); j++)
          {
            for(int k = j + 1; k < nums.size(); k++)
            {
              if(nums[i] == -(nums[j]+nums[k]))
              {
                  sumarr.push_back({nums[i], nums[j], nums[k]});
              }
            }
          }
        }
        return sumarr;
    }
};