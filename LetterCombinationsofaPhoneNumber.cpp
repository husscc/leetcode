/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

1 O_O
2 abc
3 def
4 ghi
5 jkl
6 mno
7 pqrs
8 tuv
9 wxyz
x +
0 space
^ #

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
class Solution {
    typedef pair<int,string> Make_Pair;
    void createString(string &digits,int ptr,hash_map<int,string> &hm,string str,vector<string> &res){
		if(ptr==digits.size()){
			res.push_back(str);
			return;
		}	
		else{
			string _str=hm[(int)(digits[ptr]-'0')];
			for(int i=0;i<_str.size();i++)
				createString(digits,ptr+1,hm,str+_str[i],res);
		}
	}
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        hash_map<int,string> hm;
		hm.insert(Make_Pair(2,"abc"));
		hm.insert(Make_Pair(3,"def"));
		hm.insert(Make_Pair(4,"ghi"));
		hm.insert(Make_Pair(5,"jkl"));
		hm.insert(Make_Pair(6,"mno"));
		hm.insert(Make_Pair(7,"pqrs"));
		hm.insert(Make_Pair(8,"tuv"));
		hm.insert(Make_Pair(9,"wxyz"));
		
		vector<string> res;
		string str="";
		createString(digits,0,hm,str,res);
		return res;
    }
};