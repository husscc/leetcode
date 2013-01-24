/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *start=new ListNode(0),*p1=start,*p2,*p3;
    	start->next=head;
		
		int i;
		for(i=1;i<m;i++)
			p1=p1->next;
		
		if(m<n){
			ListNode *start=p1,*end=p1->next;
			p1=p1->next;
			p2=p1->next;
			p3=p2->next;
			for(;i<n;i++){
				p2->next=p1;
				p1=p2;
				p2=p3;
                if(p3)
				    p3=p3->next;
			}
			start->next=p1;
			end->next=p2;
		}
		
		head=start->next;
		delete start;
		return head;
    }
};