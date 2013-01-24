/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    inline TreeNode* findleft(TreeNode *root){
        if(!root||!root->left)
			return NULL;
		root=root->left;
		while(root->right)
			root=root->right;
		return root;
	}
	
	inline TreeNode* findright(TreeNode *root){
		if(!root||!root->right)
			return NULL;
		root=root->right;
		while(root->left)
			root=root->left;
		return root;
	}
	
	void checkBST(TreeNode *root,TreeNode *res[],int& rescount){
		if(rescount>=2)
			return;
			
		if(root->left)
			checkBST(root->left,res,rescount);
		
		TreeNode *left_val=findleft(root);
		TreeNode *right_val=findright(root);
		
		if(left_val&&left_val->val>root->val){
			if(rescount==0){
				res[0]=left_val;
				res[1]=root;
				rescount++;
			}
			else{
				res[1]=root;
				rescount++;
			}
		}
		if(right_val&&root->val>right_val->val){
			if(rescount==0){
				res[0]=root;
				res[1]=right_val;
				rescount++;
			}
			else{
				res[1]=right_val;
				rescount++;
			}
		}	
		
		if(root->right)
			checkBST(root->right,res,rescount);
	}
	
public:
    void recoverTree(TreeNode *root) {
		// Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(!root||(!root->left&&!root->right))
			return ;
        
		TreeNode* res[2];
		int rescount=0;
		memset(res,0,2*sizeof(TreeNode*));
		
		checkBST(root,res,rescount);
		
		if(rescount>0){
			int tmp=res[0]->val;
			res[0]->val=res[1]->val;
			res[1]->val=tmp;
		}
		
		return;
	}
};