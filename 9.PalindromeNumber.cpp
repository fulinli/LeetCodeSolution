/* 
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome. 
*/
class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        for(int i = 0; i < (str.length()+1)/2; i++)
        {
            if(str[i] == str[str.length()-i-1])
                continue;
            else 
                return false;
        }
        return true;
    }
};