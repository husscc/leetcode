/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    
    inline int findelement(vector<int> &array,int begin,int end,int target){
		int i=begin;
		while(i<=end&&array[i]!=target)
			i++;
		//assert(i<=end);
		return i;
	}
	
	struct NodeInfo{
		TreeNode* root;
		int start_in;
		int end_in;
		int start_post;
		int end_post;
		NodeInfo(TreeNode* ptr,int si,int ei,int sp,int ep):root(ptr),start_in(si),end_in(ei),start_post(sp),end_post(ep){}
	};
	
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *head;
		head=NULL;
		if(inorder.size()==0)
			return head;
		if(inorder.size()==1){
			head=new TreeNode(inorder[0]);
			return head;
		}
		queue<NodeInfo> iq;
		
		int start_in,end_in,start_post,end_post,nodeidx_in,nodeidx_post;
		head=new TreeNode(postorder[postorder.size()-1]);
		iq.push(NodeInfo(head,0,inorder.size()-1,0,postorder.size()-1));
		
		while(!iq.empty()){
			if(iq.front().end_post>=iq.front().start_post){
				if(iq.front().end_post>iq.front().start_post){
					nodeidx_in=findelement(inorder,iq.front().start_in,iq.front().end_in,postorder[iq.front().end_post]);
					if(iq.front().end_in>nodeidx_in){
				
						start_in=nodeidx_in+1;
						end_post=iq.front().end_post-1;
						start_post=end_post;
						
						while(start_post>=iq.front().start_post&&findelement(inorder,iq.front().start_in,iq.front().end_in,postorder[start_post])>nodeidx_in)
							start_post--;
                            
						end_in=iq.front().end_in;
						iq.front().root->right=new TreeNode(postorder[end_post]);
						iq.push(NodeInfo(iq.front().root->right,start_in,end_in,start_post+1,end_post));
						
						if(nodeidx_in>iq.front().start_in){
							end_in=nodeidx_in-1;
							start_in=iq.front().start_in;
							end_post=start_post;
							start_post=iq.front().start_post;
							iq.front().root->left=new TreeNode(postorder[end_post]);
							
							iq.push(NodeInfo(iq.front().root->left,start_in,end_in,start_post,end_post));
						}
					}
					else{
						iq.front().root->left=new TreeNode(postorder[iq.front().end_post-1]);
						iq.push(NodeInfo(iq.front().root->left,iq.front().start_in,iq.front().end_in-1,iq.front().start_post,iq.front().end_post-1));
					}
				}
			}
			iq.pop();
		}
		
		return head;
    }
};