/*
Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
class Solution {
	void nextParenthesis(vector<string> &res,string curres,int remain,int avail_left,int avail_right){
		if(avail_right>0){
			if(remain==1){
				res.push_back(curres+')');
				return;
			}
			else
				nextParenthesis(res,curres+')',remain-1,avail_left,avail_right-1);
		}
		
		if(avail_left>0){
			nextParenthesis(res,curres+'(',remain-1,avail_left-1,avail_right+1);
		}
		return;
	}
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
		res.clear();
		if(n==0)
			return res;
		string curres="";
		nextParenthesis(res,curres,2*n,n,0);
		
		return res;
    }
};