/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    struct comp{
        bool operator()(const ListNode *p1,const ListNode *p2){
            return p1->val > p2->val;
        }
    };
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	if(lists.size()==0)
			return NULL;
		else if(lists.size()==1)
			return lists[0];
		
		ListNode *head=NULL,*ptr;
		priority_queue<ListNode*,vector<ListNode*>,comp> pq;
		
		for(int i=0;i<lists.size();i++){
    	    if(lists[i]!=NULL)
                pq.push(lists[i]);
		}
		
		if(!pq.empty()){
			head=pq.top();
			pq.pop();
			ptr=head;
		
			if(ptr->next!=NULL)
				pq.push(ptr->next);
		}
		
		while(!pq.empty()){
			ptr->next=pq.top();
			ptr=ptr->next;
			pq.pop();
			if(ptr->next!=NULL)
				pq.push(ptr->next);
		}
		
		return head;
    }	
};