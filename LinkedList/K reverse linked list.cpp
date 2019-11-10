/*
K reverse linked list
Given a singly linked list and an integer K, reverses the nodes of the 
list K at a time and returns modified linked list.
*/

ListNode* reverse (ListNode *head, int k)  
{  
    ListNode* current = head;  
    ListNode* next = NULL;  
    ListNode* prev = NULL;  
    int count = 0;  
      
    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
      
    if (next != NULL)  
    head->next = reverse(next, k);  
    
    return prev;  
}   
ListNode* Solution::reverseList(ListNode* A, int B) {
    
    return reverse(A,B);
}

