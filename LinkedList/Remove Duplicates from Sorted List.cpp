/*
Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that each e
lement appear only once. For example, Given 1->1->2, return 1->2. Given 1->1->2->3->3, return 1->2->3.
*/

ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    ListNode* curr=A;
    while(curr!=NULL)
    {
        ListNode* temp=curr->next;
        while(temp!=NULL && temp->val==curr->val)
        {
            ListNode* t=temp; delete(t);
            temp=temp->next;
        }
        curr->next=temp;
        curr=curr->next;
    }
    
    return A;
}
