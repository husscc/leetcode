/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<2)
    		return n;
		
		int sum=numTrees(n-1)*2;
		for(int i=2;i<n;i++){
			sum+=numTrees(i-1)*numTrees(n-i);
		}
		return sum;
    }
};