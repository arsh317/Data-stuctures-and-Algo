/*
Length of longest palindromic list
Given a linked list of integers. Find and return the length of the longest palindrome list that exists in that linked list. Note: A palindrome list is a list that reads the same backward and forward. Expected memory complexity : O(1)
*/

int maxmt(ListNode* A,ListNode* B)
{
    ListNode *a=A,*b=B; int mx1=0;
    while(a!=NULL && b!=NULL)
    {
        if(a->val != b->val){ break; }
        mx1++;
        a=a->next; b=b->next;
    }
    a=A->next; b=B; int mx2=0;
    while(a!=NULL && b!=NULL)
    {
        if(a->val != b->val){ break; }
        mx2++;
        a=a->next; b=b->next;
    }
    
    return max(2*mx1,2*mx2+1);
}
int Solution::solve(ListNode* A) {
    
    ListNode* curr=A,*temp=NULL,*prev=NULL;
    int mx=1;
    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        
        mx=max(mx,maxmt(prev,curr));
    }
    
    return mx;
}
