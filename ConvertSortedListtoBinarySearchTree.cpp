/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* createTree(ListNode *start,int len){
    	if(len==0)
			return NULL;
		if(len==1)
			return new TreeNode(start->val);
		
		int mid=len/2;
		ListNode *ptr=start;
		
		for(int i=0;i<mid;i++){
			ptr=ptr->next;
		}
		
		TreeNode* head=new TreeNode(ptr->val);
		if(mid>0){
			head->left=createTree(start,mid);
		}
		if(ptr->next!=NULL){
			head->right=createTree(ptr->next,len-mid-1);
		}
        return head;
	}
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		ListNode *ptr=head;
		
		if(ptr==NULL)
			return NULL;
		if(ptr->next==NULL)
			return new TreeNode(head->val);
		int len=0;	
		while(ptr!=NULL){
			len++;
			ptr=ptr->next;
		}
		return createTree(head,len);
    }
};