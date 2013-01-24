/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7]
  [9,20],
  [3],
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
    struct info{
		TreeNode *addr;
		int lvl;
		info(TreeNode *node,int level):addr(node),lvl(level){}
	};
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
		vector<int> level;
		stack<vector<int> > tmp;
		queue<info> iq;
		
		if(root==NULL)
			return res;
		
		int curlvl=0;
		info* ptr;
		iq.push(info(root,0));
		while(!iq.empty()){
			ptr=&iq.front();
			iq.pop();
			if(ptr->lvl==curlvl){
				level.push_back(ptr->addr->val);
				if(ptr->addr->left!=NULL)
					iq.push(info(ptr->addr->left,curlvl+1));
				if(ptr->addr->right!=NULL)
					iq.push(info(ptr->addr->right,curlvl+1));
			}
			else{
				tmp.push(level);
				level.clear();
				curlvl++;
				level.push_back(ptr->addr->val);
				if(ptr->addr->left!=NULL)
					iq.push(info(ptr->addr->left,curlvl+1));
				if(ptr->addr->right!=NULL)
					iq.push(info(ptr->addr->right,curlvl+1));
			}
		}
		res.push_back(level);
		while(!tmp.empty()){
			res.push_back(tmp.top());
			tmp.pop();
		}
		return res;
    }
};