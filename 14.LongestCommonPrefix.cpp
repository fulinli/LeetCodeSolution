/* 
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z. 
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string resultstr = "";
        bool ismatch = true;
        int i = 0, j = 0;
        //解决空输入问题
        if(strs.size() == 0)
        {
            return resultstr;
        }
        while(ismatch)
        {
            if(strs[0][i] != strs[j][i])
                ismatch = false;
            else
                j++;
            if(j == strs.size())
            {
                resultstr = resultstr + strs[0][i];
                j = 0;
                i++;
            }
            //strs[0].length() == 0 条件为了考虑输入[""]，不加超出内存限制
            if(i == strs[0].length() || strs[0].length() == 0)
                break;
        }
        return resultstr;
    }
};