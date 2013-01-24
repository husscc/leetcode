/*
For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    TreeNode* buildTree(TreeNode *ptr,TreeNode *res){
		TreeNode *lft, *rgt;
		lft=ptr->left;
		rgt=ptr->right;
		ptr->left=NULL;

		res->right=ptr;
		res=res->right;
		
		if(lft!=NULL){
			res=buildTree(lft,res);
		}
		if(rgt!=NULL){
			res=buildTree(rgt,res);
		}
		
		return res;
	}
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL||(root->left==NULL&&root->right==NULL))
			return;
		TreeNode *res,*lft,*rgt;
		res=root;
		lft=res->left;
		res->left=NULL;
		rgt=res->right;
		if(lft!=NULL)
			res=buildTree(lft,res);
		if(rgt!=NULL)
			res=buildTree(rgt,res);
    }
};