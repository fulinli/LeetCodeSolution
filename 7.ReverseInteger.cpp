/* 
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows. 
*/
class Solution {
public:
    int reverse(int x) {
        long long num, result;
        result = 0;
        num = (long long)x;
        int max = 2e31-1;
        int min = -2e31;
        while(num!=0)
        {
            result = num %10 + result * 10;
            num = num/10;
        }
        //if(result<-2e31||result>(2e31-1))这样写是不行的，Why?
        if(result<min || result>max)
            return 0;
        else
            return (int)result;
    }
};