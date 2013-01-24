/*
Write a function to find the longest common prefix string amongst an array of strings.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string str;
    	if(strs.size()==0)
			return str;
		int lcplen=strs[0].size(),curlen;
		
		for(int i=1;i<strs.size();i++){
			for(int j=0;j<lcplen;j++){
				if(strs[i][j]!=strs[i-1][j]){
					lcplen=j;
				}
			}
		}
		
		str=strs[0].substr(0,lcplen);
		return str;
    }
};