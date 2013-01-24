/*
Given a number represented as an array of digits, plus one to the number.
*/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	vector<int> res(digits);
        if(!res.size())
			return res;
		if(res[res.size()-1]<9){
			res[res.size()-1]++;
			return res;
		}
		
		int adv=1;
		res[res.size()-1]=0;
		for(int i=res.size()-2;adv&&i>=0;i--){
			if(res[i]==9){
				res[i]=0;
				adv=1;
			}
			else{
				res[i]++;
				adv=0;
			}
		}
		if(adv)
			res.insert(res.begin(),1);
		
		return res;
    }
};