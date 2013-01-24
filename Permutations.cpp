/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
class Solution {
    void createPermutation(hash_set<int> hs,vector<int> cur,vector<vector<int> >& res){
    	if(hs.size()){
			for(hash_set<int>::iterator it=hs.begin();it!=hs.end();it++){
				vector<int> tVec(cur);
				hash_set<int> ths(hs);
				tVec.push_back(*it);
				ths.erase(*it);
				createPermutation(ths,tVec,res);
			}
		}
		else
			res.push_back(cur);
	}
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
		vector<int> cur;
		hash_set<int> hs;
		for(int i=0;i<num.size();i++)
			hs.insert(num[i]);
		createPermutation(hs,cur,res);
		return res;
    }
};