/* 
Populate Next Right Pointers Tree
Given a binary tree
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, 
the next pointer should be set to NULL. Initially, all next pointers are set to NULL.
 Note:
You may only use constant extra space.( So Recursion not allowed as well)
Example :  Given the following binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    
    TreeLinkNode* head=A,*headn=NULL,*prev=NULL,*curr=head;
    head->next=NULL;
    
    while(head!=NULL)
    {
        curr=head;
        while(curr!=NULL)
        {
            if(curr->left!=NULL)
            {
                if(prev==NULL && headn==NULL)
                {   prev=curr->left; headn=curr->left;  }
                else
                {  prev->next=curr->left; prev=prev->next;  }
            }
            if(curr->right!=NULL)
            {
                if(prev==NULL && headn==NULL)
                {   prev=curr->right; headn=curr->right;  }
                else
                {  prev->next=curr->right; prev=prev->next;  }
            }
            curr=curr->next;
        }
        if(prev!=NULL){ prev->next=NULL; }
        head=headn;
        headn=prev=NULL;
    }
}
