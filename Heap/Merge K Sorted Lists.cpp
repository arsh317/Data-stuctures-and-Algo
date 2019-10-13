/* 
Merge K Sorted Lists
Merge k sorted linked lists and return it as one sorted list. Example :
1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in
1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class comp{
    public:
    int operator()(ListNode* a,ListNode* b)
    {
        return a->val > b->val;
    }
};   

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    
    ListNode* rt=NULL,*curr=NULL;
    
    priority_queue<ListNode*,vector<ListNode*>,comp > heap;
    for(int i=0; i<A.size(); i++)
    {
        heap.push(A[i]);
    }
    
    while(!heap.empty())
    {
        ListNode* a=heap.top();
        if(rt==NULL){ rt=a; curr=a; }
        else{ curr->next=a; curr=a;}
        
        heap.pop();
        if(a->next!=NULL){ heap.push(a->next); }
    }
    
    return rt;
}