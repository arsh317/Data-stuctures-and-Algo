/*
Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode* a,ListNode* b)
{
    if(a==NULL){ return b; }
    if(b==NULL){ return a; }
    
    ListNode* rt,*rtt;
    if(a->val <= b->val){ rtt=rt=a; a=a->next; }
    else{ rtt=rt=b; b=b->next; }
    
    while(a!=NULL && b!=NULL)
    {
        if(a->val<=b->val){ rt->next=a; a=a->next; }
        else{ rt->next=b; b=b->next; }
        rt=rt->next;
    }
    
    while(a!=NULL)
    {
        rt->next=a;
        rt=rt->next; a=a->next;
    }
    
    while(b!=NULL)
    {
        rt->next=b;
        rt=rt->next; b=b->next;
    }
    
    return rtt;
}
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    return merge(A,B);
}
