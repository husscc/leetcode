/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/
class Solution {
    void findTarget(vector<int> &num,vector<vector<int> > &res,vector<int> cur,int idx,int target){
    	if(idx>=num.size()||num[idx]>target)
			return;
		else{
			if(target==num[idx]){
				cur.push_back(num[idx]);
				res.push_back(cur);
			}
			else{
				findTarget(num,res,cur,idx+1,target);
				cur.push_back(num[idx]);
				findTarget(num,res,cur,idx+1,target-num[idx]);
			}
            return;
		}
	}
    
    struct lessvector{
        bool operator()(const vector<int> &a,const vector<int> &b){
            if(a.size()!=b.size())
                return a.size()<b.size();
            else{
                if(a.size()==0)
                    return false;
                int i=0;
                while(i<(a.size()-1)&&a[i]==b[i])
                    i++;
                return a[i]<b[i];
            }
        }
    };

public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
		res.clear();
		if(num.size()==0)
			return res;
		sort(num.begin(),num.end());
		vector<int> cur;
		cur.clear();
		findTarget(num,res,cur,0,target);
        sort(res.begin(),res.end(),lessvector());
		vector<vector<int> >::iterator uniq_iter;
        uniq_iter=unique(res.begin(),res.end());
		res.erase(uniq_iter,res.end());
		return res;
    }
};