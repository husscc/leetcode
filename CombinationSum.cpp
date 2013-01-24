/*
Combination Sum
Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

class Solution {
    void findCombination(vector<int> &candidates,vector<vector<int> > &res,vector<int> curres,int curidx,int target){
    	if(candidates[curidx]==target){
			curres.push_back(candidates[curidx]);
			res.push_back(curres);
		}
		else if(candidates[curidx]<target){		
			if(curidx+1<candidates.size()){
				findCombination(candidates,res,curres,curidx+1,target);				
			}
			curres.push_back(candidates[curidx]);
			findCombination(candidates,res,curres,curidx,target-candidates[curidx]);	
		}
		return;
	}
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(),candidates.end());
		vector<vector<int> > res;
		vector<int> curres;
		res.clear();
		curres.clear();
		
		findCombination(candidates,res,curres,0,target);
		
		return res;
    }
};