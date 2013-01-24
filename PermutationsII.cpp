/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/
class Solution {
    void createPermutation(hash_map<int,int> hm,vector<int> cur,vector<vector<int> >& res){
        if(hm.size()){
    		for(hash_map<int,int>::iterator it=hm.begin();it!=hm.end();it++){
				vector<int> tVec(cur);
				hash_map<int,int> tMap(hm);
				tVec.push_back(it->first);
				if(tMap[it->first]==1)
					tMap.erase(it->first);
				else
					tMap[it->first]--;
				createPermutation(tMap,tVec,res);
			}
		}
		else
			res.push_back(cur);
	}
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
		vector<int> cur;
		hash_map<int,int> hm;
		for(int i=0;i<num.size();i++){
			if(!hm.count(num[i]))
				hm.insert(pair<int,int>(num[i],1));
			else
				hm[num[i]]++;
		}
		createPermutation(hm,cur,res);
		return res;
    }
};