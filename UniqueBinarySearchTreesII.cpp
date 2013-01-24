/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode *> createTree(int start,int end){
    	vector<TreeNode *> res;
		
		if(start==end){
			res.push_back(new TreeNode(start));
			return res;
		}
		
		vector<TreeNode *> leftchild,rightchild;
        TreeNode *p;
		
		rightchild=createTree(start+1,end);
		for(int i=0;i<rightchild.size();i++){
			p=new TreeNode(start);
			p->right=rightchild[i];
			res.push_back(p);
		}
		
		for(int i=start+1;i<end;i++){
				leftchild=createTree(start,i-1);
				rightchild=createTree(i+1,end);
			
			for(int j=0;j<leftchild.size();j++){
				for(int k=0;k<rightchild.size();k++){
						p=new TreeNode(i);
						p->left=leftchild[j];
						p->right=rightchild[k];
						res.push_back(p);
				}
			}
		}
		
		leftchild=createTree(start,end-1);
		for(int i=0;i<leftchild.size();i++){
			p=new TreeNode(end);
			p->left=leftchild[i];
			res.push_back(p);
		}
		
		return res;
	}
	
public:
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(!n){
			vector<TreeNode *> res;
			res.push_back(NULL);
			return res;
		}
		return createTree(1,n);
    }
};