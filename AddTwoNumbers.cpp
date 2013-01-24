#include <iostream>
using namespace std;




//Definition for singly-linked list.
 struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(l1==NULL&&l2==NULL)
            return NULL;
        else if(l1==NULL||NULL==l2){
            if(NULL==l1)
                return new ListNode(l2->val);
            else
                return new ListNode(l1->val);
        }
        
        ListNode *ptr=new ListNode(l1->val+l2->val);
        ListNode *res=ptr;
        int carry=0;
        if(ptr->val>9){
            carry=1;
            ptr->val=ptr->val-10;
        }
        l1=l1->next;
        l2=l2->next;
    	
        while(l1!=NULL&&l2!=NULL){
            ptr->next=new ListNode(l1->val+l2->val+carry);
			ptr=ptr->next;
            if(ptr->val>9){
                ptr->val=ptr->val-10;
                carry=1;
            }
            else{
                carry=0;
			}
            l1=l1->next;
            l2=l2->next;
        }
        
        if(l1!=NULL||l2!=NULL){
            ListNode *ptr1;
            if(l1!=NULL)
                ptr1=l1;
            else
                ptr1=l2;
            while(NULL!=ptr1){
                ptr->next=new ListNode(ptr1->val+carry);
				ptr=ptr->next;
                if(ptr->val>9){
                    carry=1;
                    ptr->val=ptr->val-10;
                }
                else{
                    carry=0;
				}
                ptr1=ptr1->next;
                
            }
        }
        if(carry){
            ptr->next=new ListNode(1);
        }
        
        return res;
    }
};

int main(){
	ListNode *l1,*l2,*res;
	l1=new ListNode(9);
	l1->next=new ListNode(9);
	l1->next->next=new ListNode(9);
	l2=new ListNode(9);
	//l2->next=new ListNode(1);
	//l2->next->next=new ListNode(1);
	Solution s;
	res=s.addTwoNumbers(l1,l2);
	
	while(res!=NULL){
		cout<<res->val<<' ';
		res=res->next;
	}
	return 1;
}