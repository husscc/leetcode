/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head)
    		return head;
		
		ListNode *start=new ListNode(0),*pre,*pro,*ptr;
		start->next=head;
		pre=start;
		pro=head->next;
		ptr=head;
        
		
		while(n>1&&ptr->next){
			ptr=ptr->next;
			n--;
		}
		
		while(ptr->next){
			ptr=ptr->next;
			pre=pre->next;
			pro=pro->next;
		}
		
        delete pre->next;
		pre->next=pro;
		
		return start->next;
    }
};