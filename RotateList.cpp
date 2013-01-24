/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	if(head==NULL)
			return NULL;
		ListNode *rear=head;
		int len=1;
		while(rear->next!=NULL){
			len++;
			rear=rear->next;
		}
		k=len-k%len;			//be careful here
		
		rear->next=head;
		for(int i=0;i<k;i++){
			head=head->next;
			rear=rear->next;
		}
		rear->next=NULL;
		return head;
    }
};

1 2 3 1 2 3