class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n <= 0){
            return vector<string>();
        }
        vector<string> res;
        string t = "";
        generateParenthesis(res, t, n);
        return res;
    }
    void generateParenthesis(vector<string>& res, string& t, int n){
        if(t.size() == 2*n){
            //std::cout << t << std::endl;
            if(valid(t))
                res.push_back(t);
        }
        else{
            t.push_back('(');
            generateParenthesis(res, t, n);
            t.pop_back();
            t.push_back(')');
            generateParenthesis(res, t, n);
            t.pop_back();
        }
    }
    bool valid(string& t){
        int bal = 0;
        for(int i = 0; i < t.size(); i++){
            t[i] == '(' ? bal++ : bal--;
            if(bal<0)
                return false;
        }
        return bal == 0;
    }
};