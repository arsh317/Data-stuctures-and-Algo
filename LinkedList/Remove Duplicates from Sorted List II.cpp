/*
Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. For example, Given 1->2->3->3->4->4->5, 
return 1->2->5. Given 1->1->1->2->3, return 2->3.
*/


ListNode* Solution::deleteDuplicates(ListNode* A) {
     
    ListNode* curr=A;
    ListNode* prev=NULL;
    while(curr!=NULL)
    {
        ListNode* temp=curr->next; int fl=0;
        while(temp!=NULL && temp->val==curr->val)
        {
            fl=1;
            ListNode* t=temp; 
            temp=temp->next; delete(t);
        }
       
        if(fl==1)
        {  delete(curr); curr=temp; if(prev!=NULL){prev->next=NULL; } }
        else
        { 
            if(prev==NULL){ A=curr; }
            else{ prev->next=curr; }
            prev=curr;
            curr=temp; 
        }
    }
    if(prev==NULL){ return NULL; }
    return A;
    
}
