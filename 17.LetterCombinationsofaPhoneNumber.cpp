//没想出来，直接AC别人的答案, beats 5.645
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

//beats 99% solutions
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        std::map<char, std::string> sm = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        std::vector<std::string> sf;
        for (size_t i = 0; i < sm[digits[0]].size(); ++i) {
            std::string s;
            s += sm[digits[0]][i];
            sf.push_back(s);
        }
        std::vector<std::string> sn = letterCombinations(digits.substr(1));
        if(sn.empty())
            return sf;
        std::vector<std::string> sr;
        for (auto & f : sf) {
            for (auto & n : sn) {
                std::string s = "";
                s = s + f + n;
                sr.push_back(s);
            }

        }
        return sr;
    }
};