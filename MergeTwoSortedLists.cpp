/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(l1==NULL)
    		return l2;
		if(l2==NULL)
			return l1;
		
		ListNode *head,*ptr,*ptr1,*ptr2;
		if(l1->val<l2->val){
			head=l1;
			ptr1=l1->next;
			ptr2=l2;
		}
		else{
			head=l2;
			ptr1=l1;
			ptr2=l2->next;
		}
		ptr=head;
        
		while(ptr1!=NULL&&ptr2!=NULL){
			if(ptr1->val<ptr2->val){
				ptr->next=ptr1;
				ptr1=ptr1->next;
			}
			else{
				ptr->next=ptr2;
				ptr2=ptr2->next;
			}
			ptr=ptr->next;
		}
		
		if(ptr1!=NULL)
			ptr->next=ptr1;
		else if(ptr2!=NULL)
			ptr->next=ptr2;
		
		return head;
    }
};