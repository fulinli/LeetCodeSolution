/* 
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]. 
*/
class Solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            int sum;
            vector<int> result(2);
            for(int i = 0; i<nums.size(); i++)
            {
                for(int j = i+1; j<nums.size(); j++)
                {
                    sum = nums[i]+nums[j];
                    if(sum == target)
                    {
                        result[0] = i;
                        result[1] = j;
                    }
                }
            }
            return result;
        }
};
//[3,3]报错，输出为[1,1],错误原因: line17：j=i+1，之前直接定位了1;