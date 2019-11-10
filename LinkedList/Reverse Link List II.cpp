/*
Reverse Link List II
Reverse a linked list from position m to n. Do it in-place and in one-pass. 
For example: Given 1->2->3->4->5->NULL, m = 2 and n = 4, return 1->4->3->2->5->NULL.
*/

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    
    ListNode* str1=NULL,*str2=NULL,*curr=A,*prev=NULL,*temp=NULL;
    int ct1=B-1,ct2=C-1;
    
    while(ct1--){ str1=curr; curr=curr->next; ct2--; }
    str2=curr; prev=curr; temp=curr->next;
    while(ct2--)
    {
        curr=temp;
        temp=curr->next;
        curr->next=prev;
        prev=curr;
    }
    
    
    str2->next=temp;
    if(str1!=NULL){ str1->next=curr; }
    else{ A=curr; }
    
    return A;
}
