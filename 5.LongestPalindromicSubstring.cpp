/* 
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb" 
*/
class Solution
{
  public:
    string longestPalindrome(string s)
    {
        string str;
        int length;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i + 1; j <= s.length(); j++)
            {
                cout << "**********" << endl;
                cout << "i = " << i << ", j = " << j << endl;
                cout << "s.substr(i, j)=" << s.substr(i, j - i) << endl;
                if (isPalindromic(s.substr(i, j - i)))
                {
                    length = j - i;
                    cout << "length=" << length << endl;
                    if (str.length() <= length)
                        str = s.substr(i, j - i);
                }
            }
        }
        return str;
    }
    bool isPalindromic(string s)
    {
        cout << "string s = " << s << endl;
        bool isPalindromicstr;
        for (int k = 0; k < s.length(); k++)
        {
            if (s[k] == s[s.length() - k - 1])
                isPalindromicstr = true;
            else
            {
                isPalindromicstr = false;
                break;
            }
        }
        cout << "isPalindromicstr=" << isPalindromicstr << endl;
        return isPalindromicstr;
    }
};
//"dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd" 测试超过时间限制