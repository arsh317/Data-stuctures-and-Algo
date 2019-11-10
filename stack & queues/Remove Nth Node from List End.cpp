/*
Remove Nth Node from List End
Given a linked list, remove the nth node from the end of list and return its head. 
For example, Given linked list: 1->2->3->4->5, and n = 2. After removing the second node 
from the end, the linked list becomes 1->2->3->5.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    ListNode* curr=A,*temp; int ct=0;
    while(curr!=NULL)
    { ct++; curr=curr->next; }
    
    ct=ct-B+1;
    
    if(ct<1){ ct=1; }
    if(ct==1){ temp=A; A=A->next; delete(temp); return A; }
    ct-=2;
    
    curr=A;
    while(ct--)
    { curr=curr->next;  }
    
    temp=curr->next;
    curr->next=temp->next;
    delete(temp);
    
    return A;
}
