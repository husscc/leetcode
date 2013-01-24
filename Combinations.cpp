/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
    void findComb(vector<vector<int> > &res,vector<int> tmpres,int idx,int remain,int &n){
    	if(remain==0){
            res.push_back(tmpres);   
    	}
        else if(remain==(n+1-idx)){
			while(remain>0){
				tmpres.push_back(idx);
				idx++;
				remain--;
			}
			res.push_back(tmpres);
		}
		else{
			findComb(res,tmpres,idx+1,remain,n);
			tmpres.push_back(idx);
			findComb(res,tmpres,idx+1,remain-1,n);
		}
		return;
	}
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
		res.clear();
		if(n==0||k==0)
			return res;
		
		vector<int> tmpres;
		tmpres.clear();
		k=k<n?k:n;
		findComb(res,tmpres,1,k,n);
		return res;
    }
};