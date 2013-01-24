/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, 
only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head||!head->next)
            return head;
    
        ListNode *start=new ListNode(0);
        start->next=head;
        
        ListNode *ptr=start;
        
        while(ptr->next&&ptr->next->next){
            ListNode *tmp1=ptr->next,*tmp2=tmp1->next;
            tmp1->next=tmp2->next;
            tmp2->next=tmp1;
            ptr->next=tmp2;
            ptr=tmp1;
        }
        
        head=start->next;
        delete start;
        return head;
        
    }
};