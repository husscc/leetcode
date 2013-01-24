/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    void createPath(TreeNode *root,int sum,vector<int> path,vector<vector<int> >& res){
		path.push_back(root->val);
		if(!root->left&&!root->right){
			if(root->val==sum)
				res.push_back(path);
		}
		else{
			if(root->left)
				createPath(root->left,sum-root->val,path,res);
			if(root->right)
				createPath(root->right,sum-root->val,path,res);
		}
	}
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
		if(!root)
			return res;
		
		vector<int> path;
		path.push_back(root->val);
		
		if(!root->left&&!root->right){
			if(root->val==sum)
				res.push_back(path);
		}
		else{
			if(root->left)
				createPath(root->left,sum-root->val,path,res);
			if(root->right)
				createPath(root->right,sum-root->val,path,res);
		}
		
		return res;
    }
};