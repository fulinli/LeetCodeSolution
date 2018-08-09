class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res, val, buttons;
        int n = digits.length();
        buttons.push_back("");
        buttons.push_back("");
        buttons.push_back("abc");
        buttons.push_back("def");
        buttons.push_back("ghi");
        buttons.push_back("jkl");
        buttons.push_back("mno");
        buttons.push_back("pqrs");
        buttons.push_back("tuv");
        buttons.push_back("wxyz");
        for(int i = 0; i < n; i++){
            int num = (int)(digits[i] - 48);
            val.push_back(buttons[num]);
        }
        
    }
};