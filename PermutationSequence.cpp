/*
The set [1,2,3,бн,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/
class Solution {
    inline int factorial(int n){
		int res=1;
		for(int i=2;i<=n;i++)
			res*=i;
		return res;
	}
	inline void swapchar(char &a,char &b){
		if(a!=b){
            char tmp=a;
			a=b;
			b=tmp;
		}
	}
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string str="";
		if(!n||!k)
			return str;
		
		int total=factorial(n);
        k=k%(total+1);
		
		for(int i=1;i<=n;i++)
			str+='0'+i;
        
		for(int i=2;i<=k;i++){
			int p=str.size()-1,p_mirror,min_greater_idx;
			while(p>=-1&&str[p-1]>str[p])
				p--;
				
			min_greater_idx=p;
			p_mirror=p+1;
			
			while(p_mirror<str.size()){
				if(str[p_mirror]>str[p-1]&&str[p_mirror]<str[min_greater_idx])
					min_greater_idx=p_mirror;
					
				p_mirror++;
			}
			
			swapchar(str[p-1],str[min_greater_idx]);
			
			for(p_mirror=str.size()-1;p<p_mirror;p++,p_mirror--)
				swapchar(str[p],str[p_mirror]);
		}
		return str;
    }
};