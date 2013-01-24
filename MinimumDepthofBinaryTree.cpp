/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
			return 0;
		if(!root->left&&!root->right)
			return 1;
		
		if(root->left&&root->right)
			return 1+min(minDepth(root->left),minDepth(root->right));
		else if(!root->left)
			return 1+minDepth(root->right);
		else
			return 1+minDepth(root->left);
    }
};