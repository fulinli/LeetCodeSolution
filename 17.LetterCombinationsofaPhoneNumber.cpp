//没想出来，直接AC别人的答案
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n = digits.length();
        if(n <= 0){
            return vector<string>();
        }
        string base[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string t;
        letterCombination(digits, res, 0, t, base);
    
        return res;
    }
    void letterCombination(string& digits, vector<string>& res, int index, string& t, string base[]){
        if(index == digits.length()){
            res.push_back(t);
            return;
        }
        
        for(int i = 0; i < base[digits[index] - '0'].length(); i++){
            t += base[digits[index] - '0'][i];
            letterCombination(digits, res, index + 1, t, base);
            t.pop_back();
        }
    }
};