/* 
Kth Smallest Element In Tree
Given a binary search tree, write a function to find the kth smallest element in the tree. Example :
Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.

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


int morristrv(TreeNode* A, int B)
{
    TreeNode* curr=A; int ct=0;
    while(curr!=NULL)
    {
        if(curr->left!=NULL)
        {
            TreeNode* t=curr->left;
            while(t->right!=NULL && t->right!=curr)
            {  t=t->right;  }
            
            if(t->right==NULL)
            {
                t->right=curr;
                curr=curr->left;
            }
            else//t->right=curr
            {
                t->right=NULL; ct++;
                if(ct==B){ return curr->val; }
                curr=curr->right;
            }
        }
        else
        {
            ct++;
            if(ct==B){ return curr->val; }
            curr=curr->right;
        }
    }
}

int Solution::kthsmallest(TreeNode* A, int B) {
    
    return morristrv(A,B);
}
