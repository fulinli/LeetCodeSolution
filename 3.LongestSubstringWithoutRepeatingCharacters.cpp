/* 
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring. 
*/
//提交的时候要删掉所有的cout，否则会报错超出限制。
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        string substr;
        int maxlength = 0, length = 0, i = 0, iter = 0;
        bool isappend = true;
        while (i < s.length())
        {
            cout << "*******" << endl;
            for (int j = 0; j <= substr.length(); j++)
            {
                if (substr[j] == s[i])
                {
                    isappend = false;
                    break;
                }
            }
            if (isappend == true)
            {
                substr.append(s, i, 1);
                length = substr.length();
                cout << "substr=" + substr << endl;
                cout << "length=" << length << endl;
            }
            if (isappend == false)
            {
                isappend = true;
                cout << "clear" << endl;
                substr.clear();
                cout << "substr=" + substr << endl;
                i = iter;
                cout << "iter=" << iter << endl;
                iter++;
            }
            maxlength = length > maxlength ? length : maxlength;
            i++;
            cout << "i=" << i << endl;
        }
        return maxlength;
    }
};