#include <iostream>
#include <vector>
#include <string>
class Solution{
public:
	std::vector<std::string> generateParenthesis(int n){
		using namespace std;
		if(n <= 0){
			return vector<string>();
		}
		string p = "()";
		vector<string> res;
		string t;
		generateParenthesis(n, t, res, p, 0);

		return res;
	}
	void generateParenthesis(int n, std::string& t, std::vector<std::string>& res, std::string p, int index){
		using namespace std;
		if(index == n){
			res.push_back(t);
			return ;
		}
		for(i = 0; i < p.length(); i++){
			t += p[i];
			generateParenthesis(n, t, res, p, index+1);
			t.pop_back();
		}
	}
};
