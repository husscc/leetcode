/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
    void createSubset(vector<int> &S,int index,vector<int> buffer,vector<vector<int> > &res){
		if(index==S.size())
			res.push_back(buffer);
		else{
			createSubset(S,index+1,buffer,res);
			buffer.push_back(S[index]);
			createSubset(S,index+1,buffer,res);
		}
		return;
	}
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
		vector<int> buffer;
        if(S.size()>1)
            sort(S.begin(),S.end(),less<int>());
		createSubset(S,0,buffer,res);
		return res;
    }
};