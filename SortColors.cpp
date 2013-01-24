/*
Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/
class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int p=-1;
		for(int i=0;i<n;i++){
			if(A[i]<1)
				swap(A[++p],A[i]);
		}
		for(int i=p;i<n;i++){
			if(A[i]<2)
				swap(A[++p],A[i]);
		}
		
		return;
    }
};