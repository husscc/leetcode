/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
    int returnMax(TreeNode* node,int& max){
    	if(node==NULL)
			return 0;
		else{
			int leftval=returnMax(node->left,max),rightval=returnMax(node->right,max);
			leftval=leftval>0?leftval:0;
			rightval=rightval>0?rightval:0;
			max=max>(leftval+rightval+node->val)?max:(leftval+rightval+node->val);
			return node->val+(leftval>rightval?leftval:rightval);
		}
	}
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max=-100;
		returnMax(root,max);
		return max;
    }
};