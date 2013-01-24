/*
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function	
		ListNode *tmp_head=new ListNode(0);	
		tmp_head->next=head;
		
		ListNode *p_pre=tmp_head,*p=head,*to_del;
		bool isDuplicated;
		
		while(p){
			isDuplicated=false;
			while(p->next&&p->val==p->next->val){
				isDuplicated=true;
				to_del=p;
				delete to_del;
				p=p->next;
			}
			
			if(isDuplicated){
				p_pre->next=p->next;
				delete p;
				p=p_pre->next;
			}
			else{
				p_pre=p_pre->next;
				if(p_pre)
					p=p_pre->next;
				else
					break;
			}
		}
		
		head=tmp_head->next;
		delete tmp_head;
		
		return head;
    }
};