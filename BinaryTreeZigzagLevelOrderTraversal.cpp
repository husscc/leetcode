/*
Given a binary tree, return the zigzag level order traversal of its nodes' values.
 (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3			->
   / \
  9  20			<-
    /  \
   15   7		->
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
		int level;
		info(TreeNode *node,int x):addr(node),level(x){}
	};
	
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
		if(root==NULL)
			return res;
		
		vector<int> samelevel;
		queue<info> iq;
		//stack<int> 
		info *ptr;
		int curlevel=0,direction=0; //0: from left to right; 1: from right to left
		iq.push(info(root,0));
		while(!iq.empty()){
			ptr=&iq.front();
			iq.pop();
			if(ptr->level==curlevel){
				samelevel.push_back(ptr->addr->val);
				if(ptr->addr->left!=NULL)
					iq.push(info(ptr->addr->left,curlevel+1));
				if(ptr->addr->right!=NULL)
					iq.push(info(ptr->addr->right,curlevel+1));
			}
			else{
				curlevel++;
				if(direction==0)
					direction=1;
				else{
					direction=0;
					for(int i=0,j=samelevel.size()-1;i<j;i++,j--){
						samelevel[i]=samelevel[i]^samelevel[j];
						samelevel[j]=samelevel[i]^samelevel[j];
						samelevel[i]=samelevel[i]^samelevel[j];
					}
				}
				res.push_back(samelevel);
				samelevel.clear();
				
				samelevel.push_back(ptr->addr->val);
				if(ptr->addr->left!=NULL)
					iq.push(info(ptr->addr->left,curlevel+1));
				if(ptr->addr->right!=NULL)
					iq.push(info(ptr->addr->right,curlevel+1));
			}
		}
		
		if(direction){
			for(int i=0,j=samelevel.size()-1;i<j;i++,j--){
				samelevel[i]=samelevel[i]^samelevel[j];
				samelevel[j]=samelevel[i]^samelevel[j];
				samelevel[i]=samelevel[i]^samelevel[j];
			}
		}
		
		res.push_back(samelevel);
		return res;
    }
};