/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
        	return;
			
		TreeLinkNode *ptr=root,*_next=NULL;
		
		while(ptr){
			if(ptr->left){
				_next=ptr->left;
				break;
			}
			if(ptr->right){
				_next=ptr->right;
				break;
			}
			ptr=ptr->next;
		}
		
		if(_next){
			TreeLinkNode *p_next=ptr;
			while(ptr){
				if(ptr->left){
					while(p_next){
						if(p_next->right){
							ptr->left->next=p_next->right;
							break;
						}
						if(p_next->next&&p_next->next->left){
							p_next=p_next->next;
							ptr->left->next=p_next->left;
							break;
						}
						p_next=p_next->next;
					}
				}
				if(ptr->right){
					p_next=p_next->next;
					while(p_next){
						if(p_next->left){
							ptr->right->next=p_next->left;
							break;
						}
						if(p_next->right){
							ptr->right->next=p_next->right;
							break;
						}
						p_next=p_next->next;
					}
				}
				ptr=p_next;
			}
			connect(_next);
		}
    }
};