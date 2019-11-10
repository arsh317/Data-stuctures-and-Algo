/*
Intersection of Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.
 */


int len(ListNode* a)
{
    ListNode* rt=a; int ct=0;
    while(rt!=NULL)
    { ct++; rt=rt->next; }
    return ct;
}
ListNode* getint(ListNode* A, ListNode* B)
{
    int ct=len(A)-len(B);
    while(ct--){ A=A->next; }
    
    while(A!=NULL && B!=NULL)
    {
        if(A==B){ return A; }
        A=A->next; B=B->next;
    }
    return NULL;
}
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    
    if(len(A)>=len(B)){ return getint(A,B); }
    return getint(B,A);
}
