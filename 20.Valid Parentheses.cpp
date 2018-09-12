/* 
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true 
*/
class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        int j = 0;
        while(j < s.length()){
            if(s[j] == '(' || s[j] == '{' || s[j] == '['){
                stack.push_back(s[j]);
            }
            else if(stack.size() != 0 && (s[j] == ')' && stack.back() == '(' || s[j] == '}' && stack.back() == '{' || s[j] == ']' && stack.back() == '[')){
                stack.pop_back();
            }
            else
                return false;
            ++j;
        }
        if(stack.size() == 0)       
            return true;
        else
            return false;
    }
};