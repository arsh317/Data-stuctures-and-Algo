/*
List Cycle
Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null. Try solving it using constant additional space.
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    
    ListNode *slow=A,*fast=A;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast){ break; }
    }
    if(slow!=fast){ return NULL; }
    
    slow=A;
    
    while(1)
    {
        if(slow==fast){ return slow; }
        slow=slow->next;
        fast=fast->next;
    }
   
}
