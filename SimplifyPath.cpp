/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/
class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string res="";
        
        for(int i=0;i<path.size();){
    		int j=i+1;
			
			while(j<path.size()&&path[j]!='/')
				j++;
				
			if((i+2==j)&&(path.substr(i,2)=="/.")){}							
				// case:"/./"

			else if((i+3==j)&&(path.substr(i,3)=="/..")){								
				// case:"/../"
                int k=res.size()-1;
				while(k>0&&res[k]!='/') {k--;}
				if(res.size()>k)
					res.erase(k,res.size()-k);
			}
			else if(j!=i+1){
                res+=path.substr(i,j-i);
			}
			
			i=j;
			
			while(i<(path.size()-1)&&path[i+1]=='/')
				i++;
		}
		if(res=="")
			res+='/';
		return res;
    }
};