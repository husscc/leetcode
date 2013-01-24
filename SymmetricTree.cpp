/*
Given a binary tree, check whether it is a mirror of itself
(ie, symmetric around its center).

For example, this binary tree is symmetric:

        1
	   / \
	  2   2
	 / \ / \
    3  4 4  3
But the following is not:
	    1
	   / \
	  2   2
	   \   \
	   3    3
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
    struct NodeInfo{
    	TreeNode *node;
		int level;
		int idx;
		NodeInfo(TreeNode *ptr,int l,int i):node(ptr),level(l),idx(i){}
	};
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(!root||(!root->left&&!root->right))
			return true;
		else if(!root->left||!root->right)
			return false;
		
		stack<int> node_val;
		stack<int> node_idx;
		queue<NodeInfo> node_queue;
		
		node_queue.push(NodeInfo(root->left,2,1));
		node_queue.push(NodeInfo(root->right,2,2));
		
		int level=2,leftside=1;

		while(!node_queue.empty()){
			while(!node_queue.empty()&&node_queue.front().level==level){
				if(node_queue.front().idx<=leftside){
					node_val.push(node_queue.front().node->val);
					node_idx.push(node_queue.front().idx);
				}
				else{
					if(
                        node_val.empty()
						||((leftside-node_queue.front().idx)!=(node_idx.top()-leftside-1))
						||(node_queue.front().node->val!=node_val.top())
					)
						return false;
					else{
						node_idx.pop();
						node_val.pop();
					}
				}
				if(node_queue.front().node->left)
					node_queue.push(NodeInfo(node_queue.front().node->left,node_queue.front().level+1,2*node_queue.front().idx-1));
				if(node_queue.front().node->right)
					node_queue.push(NodeInfo(node_queue.front().node->right,node_queue.front().level+1,2*node_queue.front().idx));
				
				node_queue.pop();
			}
			if(!node_val.empty())
				return false;
				
			level++;
			leftside*=2;
		}
		return true;
    }
};