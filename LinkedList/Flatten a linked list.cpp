/*
Flatten a linked list
Given a linked list where every node represents a linked list and contains two pointers of its type:
Pointer to next node in the main list (right pointer)
Pointer to a linked list where this node is head (down pointer). All linked lists are sorted.
You are asked to flatten the linked list into a single list. Use down pointer to link nodes of the flattened list. The flattened linked list should also be sorted.
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
    if(a->val <= b->val){ rtt=rt=a; a=a->down; }
    else{ rtt=rt=b; b=b->down; }
    
    while(a!=NULL && b!=NULL)
    {
        if(a->val<=b->val){ rt->down=a; a=a->down; }
        else{ rt->down=b; b=b->down; }
        rt=rt->down;
    }
    
    while(a!=NULL)
    {
        rt->down=a;
        rt=rt->down; a=a->down;
    }
    
    while(b!=NULL)
    {
        rt->down=b;
        rt=rt->down; b=b->down;
    }
    
    return rtt;
}

ListNode* flatten (ListNode* root) {
    
    ListNode* curr=root;
    while(curr->right!=NULL)
    {
        ListNode* rgt=curr->right;
        curr=merge(curr,rgt);
        curr->right=rgt->right;
    }
    
    return root;

}