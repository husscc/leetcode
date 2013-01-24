/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    void buildTree(TreeNode *root,vector<int> &num,int start,int end){
    	if(start==end)
			return;
		int mid=start+(end-start)/2;
		
		if(mid>start){
			root->left=new TreeNode(num[start+(mid-1-start)/2]);
			buildTree(root->left,num,start,mid-1);
		}
		
		if(mid<end){
			root->right=new TreeNode(num[mid+1+(end-mid-1)/2]);
			buildTree(root->right,num,mid+1,end);
		}
	}
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size()==0)
			return NULL;
		if(num.size()==1)
			return new TreeNode(num[0]);
		
		TreeNode *head=new TreeNode(num[(num.size()-1)/2]);
		buildTree(head,num,0,num.size()-1);	//(end-start)/2+1
		
		return head;
    }
};