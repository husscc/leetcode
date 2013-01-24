/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head||!head->next||k<2)
    		return head;
		
		ListNode *start=new ListNode(0);
		start->next=head;
		
		ListNode *begin=start,*end,*p1,*p2,*p3;
		
		while(p2){
			ListNode *test=begin;
			
			int i=0;
			while(i<k&&test){
				i++;
				test=test->next;
			}
			
			if(!test)
				break;
			else{
				p1=begin->next;
				p2=p1->next;
				p3=p2->next;
				end=p1;
				for(int i=1;i<k;i++){
					p2->next=p1;
					p1=p2;
					p2=p3;
					if(p3)
						p3=p3->next;
				}
				begin->next=p1;
				end->next=p2;
				
				begin=end;
			}
		}
		
		head=start->next;
		delete start;
		
		return head;
    }
};