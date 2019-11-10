/*
Clone a linked list
Given a doubly linked list of integers with one pointer of each node 
pointing to the next node (just like in a single link list) while the second pointer, 
however, can point to any node in the list and not just the previous node. 
You have to create a copy of this list and return the head pointer of the duplicated list. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* clonelist(ListNode *A) {
    
    if(A==NULL){ return A; }
    ListNode* curr=A;
    
    while(curr!=NULL)
    {
        ListNode *nw=new ListNode(curr->val);
        ListNode*tmp=curr->next;
        curr->next=nw;
        nw->next=tmp;
        curr=tmp;
    }
    
    curr=A;
    while(curr!=NULL)
    {
        (curr->next)->random=(curr->random)->next;
        curr=curr->next->next;
    }
    
    ListNode* nA=A->next;
    curr=A;
    
    while(curr->next->next!=NULL)
    {
        ListNode* nw=curr->next;
        curr->next=curr->next->next;
        nw->next=nw->next->next;
    }
    curr->next=NULL;
    
    return nA;

}