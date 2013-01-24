/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].
Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
    	if(root==NULL)
			return res;
			
        stack<TreeNode*> tstack;
		TreeNode *ptr;
		
		tstack.push(root);
		ptr=root->left;
		while((ptr!=NULL)||(!tstack.empty())){
			if(ptr!=NULL){
				tstack.push(ptr);
				ptr=ptr->left;
			}
			else{
                ptr=tstack.top();
				res.push_back(ptr->val);
				ptr=ptr->right;
				tstack.pop();
			}
		}
		return res;
    }
};