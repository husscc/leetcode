/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
/*

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
    bool compleft(int nVal,TreeNode* leftnode){
		while(leftnode->right!=NULL)
			leftnode=leftnode->right;
		if(nVal>leftnode->val)
			return true;
		else
			return false;
	}
	bool compright(int nVal,TreeNode* rightnode){
		while(rightnode->left!=NULL)
			rightnode=rightnode->left;
		if(nVal<rightnode->val)
			return true;
		else
			return false;
	}
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	queue<TreeNode*> q;
		TreeNode *ptr;
		//q.clear();
		if(root!=NULL)
			q.push(root);
		while(q.size()>0){
			ptr=q.front();
			q.pop();
			if(ptr->left!=NULL){
				if(compleft(ptr->val,ptr->left))
					q.push(ptr->left);
				else
					return false;
			}
			if(ptr->right!=NULL){
				if(compright(ptr->val,ptr->right))
					q.push(ptr->right);
				else
					return false;
			}
		}
			
        return true;
    }
};