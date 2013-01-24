/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class Solution {
    struct compvec{
        bool operator()(const vector<int> &v1,const vector<int> &v2){
		    if(v1.size()<v2.size())
			    return true;
		    else if(v1.size()>v2.size())
		    	return false;
	    	else{
			    int i=0;
		    	while(i<v1.size()){
			    	if(v1[i]<v2[i])
			    		return true;
			    	else if(v1[i]>v2[i])
				    	return false;
                    i++;
		    	}
		    	return false;
	    	}
	    }
    };
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
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
		vector<int> buffer;
		if(S.size()>1)
			sort(S.begin(),S.end(),less<int>());
		createSubset(S,0,buffer,res);
		if(res.size()>1)
			sort(res.begin(),res.end(),compvec());
		res.resize(distance(res.begin(),unique(res.begin(),res.end())));
		return res;
    }
};