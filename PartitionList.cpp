/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	if(!head)
			return head;
			
		ListNode *lHead=NULL,*gHead=NULL,*lptr,*gptr;
		ListNode *ptr=head;
		
		while(ptr!=NULL){
			if(ptr->val<x){
				if(lHead==NULL){
					lHead=ptr;
					ptr=ptr->next;
					lHead->next=NULL;
					lptr=lHead;
				}
				else{
					lptr->next=ptr;
					lptr=lptr->next;
					ptr=ptr->next;
					lptr->next=NULL;
				}
			}
			
			else{
				if(gHead==NULL){
					gHead=ptr;
					ptr=ptr->next;
					gHead->next=NULL;
					gptr=gHead;
				}
				else{
					gptr->next=ptr;
					gptr=gptr->next;
					ptr=ptr->next;
					gptr->next=NULL;
				}
			}
		}
        
		if(lHead!=NULL)
			lptr->next=gHead;
		else
			lHead=gHead;
			
		return lHead;
	}		
};