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
 
ListNode* rev(ListNode* A)
{
    ListNode* curr=A,*prev=NULL,*temp=NULL;
    
    while(curr!=NULL)
    {
        A=curr;
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return A;
}
 
int Solution::lPalin(ListNode* A) {
    
    if(A->next==NULL){ return 1; }
    
    int ct=0;
    ListNode* slow=A,*fast=A;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next; ct++;
        fast=fast->next->next;
    }
    ListNode* last=rev(slow);
    //cout<<slow->val<<endl;
    //while(last!=NULL){ cout<<last->val; last=last->next; }
    slow=A;
    
    while(last!=NULL && slow!=NULL)
    {
        if(slow->val != last->val){ return 0; }
        slow=slow->next;
        last=last->next;
    }
    
    return 1;
    
}
