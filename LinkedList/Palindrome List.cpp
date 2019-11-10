/*
Palindrome List
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively. Notes:
Expected solution is linear in time and constant in space.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    
    if(A==NULL || A->next==NULL){ return 1; }
    
    ListNode* curr=A,*temp=NULL,*prev=NULL,*slow=A,*fast=A;
    
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next; 
        fast=fast->next->next;
    }
    int fl=0;
    if(fast->next==NULL){ fl=1; }
    //cout<<slow->val<<" "<<fast->val<<endl;
    ListNode *chk=slow->next;
    while(curr!=chk)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    if(fl){ slow=slow->next;  }
    //cout<<slow->val<<" "<<chk->val<<endl;
    while(slow!=NULL && chk!=NULL)
    {
        if(slow->val != chk->val){ return 0; }
        slow=slow->next; chk=chk->next;
    }
    
    return 1;
    
}