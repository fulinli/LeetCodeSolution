/* 
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);
Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I 
*/
//个人解法，主要讲Z字形变换看作是W形的变换，声明一个numRows×s.length()的数组, 将s中的每个字符从上往下，从左往右向数组中赋值。最后再按一行一列将字符读出。
class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> ZZarr(numRows, vector<char>(s.length()));
        string str = "";
        bool goingDown = true;
        if(numRows == 1)
            str = s;
        else
        {
            for(int i = 0, j = 0; i < s.length(); i++)
            {
                ZZarr[j][i]=s[i];
                if(j == numRows - 1)
                {
                    goingDown = false;    
                }
                if(j == 0)
                {
                    goingDown = true;
                }
                if(goingDown)
                    j++;
                else
                    j--;
            }
            for(int j = 0; j < numRows; j++)
            {
                for(int i = 0; i < s.length(); i++)
                {
                    if(ZZarr[j][i] != '\0')
                        str = str + ZZarr[j][i];
                }
            }
        }
        return str;
    }
};