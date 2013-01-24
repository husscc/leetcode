/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int p=0;
    	while(p<n&&A[p]!=elem)
			p++;
		
		int _p=p+1;
		while(_p<n){
			if(A[_p]!=elem)
				swap(A[p++],A[_p]);
			_p++;
		}
		return p;
    }
};