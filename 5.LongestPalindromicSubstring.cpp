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
//Solution1为暴力法，超出时间限制。
class Solution1
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
//Solution2 
//2018-7-25通过学习，使用了动态规划方法，写的混乱，未通过。
//2018-7-28修改后，应该是可以通过的，可是leetcode报错，执行代码可以通过，提交解答未通过
class Solution2 {
public:
    string longestPalindrome(string s) 
    {
        string str;
        int maxlength = 1;
        int strlength = s.length();
        int dp[1000][1000];
        for(int i = 0; i < strlength; i++)
        {
            dp[i][i] = 1;
            if(maxlength<=1)
                str = s.substr(i, 1);
            if(i<=strlength-1)
            {
                if(s[i+1] == s[i])
                { 
                    dp[i][i+1] = 1;
                    maxlength = 2;
                    str = s.substr(i, 2);
                }
            }
        }
        for(int L = 3; L <= strlength; L++)
        {
            for(int j = 0; j < strlength - L + 1; j++)
            {
                if((s[j] == s[L+j-1]) && dp[j+1][L+j-2]==1)
                {
                    dp[j][L+j-1] = 1;
                    if(L>=maxlength)
                    {
                        str = s.substr(j, L);
                        maxlength = L;
                    }
                }
            }
        }
        return str;
    }
};
//基本方法沿用solution2，没有用静态数组，采用动态数组后提交通过。
class Solution3 {
public:
    string longestPalindrome(string s) {
        string str;
        int maxlength = 1;
        int strlength = s.length();
        //*********************************************************************
        vector<vector<int> > dp(s.length(),vector<int>(s.length()));
        //*********************************************************************
        //int dp[1000][1000];
        for(int i = 0; i < strlength; i++)
        {
            dp[i][i] = 1;
            if(maxlength<=1)
                str = s.substr(i, 1);
            if(i<=strlength-1)
            {
                if(s[i+1] == s[i])
                { 
                    dp[i][i+1] = 1;
                    maxlength = 2;
                    str = s.substr(i, 2);
                }
            }
        }
        for(int L = 3; L <= strlength; L++)
        {
            for(int j = 0; j < strlength - L + 1; j++)
            {
                if((s[j] == s[L+j-1]) && dp[j+1][L+j-2]==1)
                {
                    dp[j][L+j-1] = 1;
                    if(L>=maxlength)
                    {
                        str = s.substr(j, L);
                        maxlength = L;
                    }
                }
            }
        }
        return str;
    }
};