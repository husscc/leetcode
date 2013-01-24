/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/
//Judge Large Not Pass 
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
    inline int findelement(vector<int> &num,int start,int end,int target){
        while(start<=end&&num[start]!=target)
			start++;
		return start;
	}
	struct NodeInfo{
		TreeNode *root;
		int start_pre;
		int end_pre;
		int start_in;
		int end_in;
		NodeInfo(TreeNode *ptr,int sp,int ep,int si,int ei):root(ptr),start_pre(sp),end_pre(ep),start_in(si),end_in(ei){}
	};
	
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		TreeNode *head;
		if(preorder.size()==0)
			return NULL;
			
		head=new TreeNode(preorder[0]);
		if(preorder.size()==1)
			return head;
			
		queue<NodeInfo> niq;
		
		niq.push(NodeInfo(head,0,preorder.size()-1,0,inorder.size()-1));
		int nodeidx_in,start_pre,end_pre,start_in,end_in;
	
		
		while(!niq.empty()){
			if(niq.front().start_pre<niq.front().end_pre){
				nodeidx_in=findelement(inorder,niq.front().start_in,niq.front().end_in,preorder[niq.front().start_pre]);
				if(niq.front().start_in<nodeidx_in){	//left substree exists
					start_pre=niq.front().start_pre+1;
					start_in=niq.front().start_in;
					end_pre=start_pre;
					while(
							end_pre<=niq.front().end_pre
							&&
                            nodeidx_in>findelement(inorder,niq.front().start_in,niq.front().end_in,preorder[end_pre])
						)
						end_pre++;
					end_in=nodeidx_in-1;
					niq.front().root->left=new TreeNode(preorder[start_pre]);
					niq.push(NodeInfo(niq.front().root->left,start_pre,end_pre-1,start_in,end_in));
						
					if(nodeidx_in<niq.front().end_in){			//right substree exists
						start_pre=end_pre;
						end_pre=niq.front().end_pre;
						start_in=nodeidx_in+1;
						end_in=niq.front().end_in;
						niq.front().root->right=new TreeNode(preorder[start_pre]);
						niq.push(NodeInfo(niq.front().root->right,start_pre,end_pre,start_in,end_in));
					}
				}
				else{	//only right substree
					start_pre=niq.front().start_pre+1;
					end_pre=niq.front().end_pre;
					start_in=niq.front().start_in+1;
					end_in=niq.front().end_in;
					niq.front().root->right=new TreeNode(preorder[start_pre]);
					niq.push(NodeInfo(niq.front().root->right,start_pre,end_pre,start_in,end_in));
				}
			}
			niq.pop();  
		}
		return head;
    }
};