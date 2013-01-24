/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
such that adding up all the values along the path equals the given sum.

For example
Given the below binary tree and sum = 22,
              5
              
            4   8
               
          11  13  4
                 
        7    2      1
return true, as there exist a root-to-leaf path 5-4-11-2 which sum is 22.
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
    void pathSum(TreeNode *root,int sum, bool& isExist){
		if(isExist)
			return;
		if(!root->left&&!root->right){
            if(sum==root->val)
			    isExist=true;
		}
		else{
			if(root->left)
				pathSum(root->left,sum-root->val,isExist);
			if(root->right)
				pathSum(root->right,sum-root->val,isExist);
		}
	}
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
			return false;
		
		if(!root->left&&!root->right){
			if(sum==root->val)
				return true;
			else
				return false;
		}
		else{
			bool isExist=false;
			if(root->left)
				pathSum(root->left,sum-root->val,isExist);
			if(root->right)
				pathSum(root->right,sum-root->val,isExist);
			return isExist;
		}
    }
};