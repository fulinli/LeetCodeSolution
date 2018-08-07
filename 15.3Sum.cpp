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
//想法2：看了题解，固定一个数，然后再做另外两个数的Twosum，发现不知道如何排除掉已经存在的元组...遂看答案了...
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
        int n = nums.size();
        //如果数组的长度小于3，直接返回0；
        if(n < 3){
          return res;
        }
        
        //将数组从小到大的排序
        sort(nums.begin(), nums.end());
        
        //定义临时数组用于存储找到的sum of zero的数
        vector<int> t(3);
        int i = 0, j = 0 ,k = 0;
        int val;

        while(i < n && nums[i] <= 0){
          t[0] = nums[i];
          j = i + 1;
          k = n - 1;
          while(j < k){
            val = nums[i] + nums[j] + nums[k];
            if(val < 0){
              j++;
              continue;
            }
            if(val > 0){
              k--;
              continue;
            }
            while(nums[j] == nums[j+1] && j + 1 < k){
              j++;
            }
            t[1] = nums[j];
            t[2] = nums[k];
            res.push_back(t);
            j++;
          }
          while(i + 1 < n && nums[i] == nums[i+1]){
            i++;
          }
          i++;
        }
        return res;
    }
};


//别人AC的答案
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        
        vector<int> t(3);
        int i, j, k;
        int val;
        
        i = 0;
        while (i < n && nums[i] <= 0) {
            t[0] = nums[i];
            j = i + 1;
            k = n - 1;
            while (j < k) {
                val = nums[i] + nums[j] + nums[k];
                if (val < 0) {
                    ++j;
                    continue;
                }
                if (val > 0) {
                    --k;
                    continue;
                }
                t[1] = nums[j];
                t[2] = nums[k];
                res.push_back(t);
                while (j + 1 < k && nums[j] == nums[j + 1]) {
                    ++j;
                }
                ++j;
            }
            // Skip duplicate results
            while (i + 1 < n && nums[i] == nums[i + 1]) {
                ++i;
            }
            ++i;
        }
        
        return res;
    }
};