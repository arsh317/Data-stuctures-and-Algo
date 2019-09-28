/* 
Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place. Example : Given
         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.
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


 
pair<TreeNode*,TreeNode*> flat(TreeNode* A)
{
    if(A==NULL){ return make_pair(A,A); }
    if(A->left==NULL && A->right==NULL){ return make_pair(A,A); }
    
    pair<TreeNode*,TreeNode*> l=flat(A->left);
    pair<TreeNode*,TreeNode*> r=flat(A->right);
    
    if(A->left==NULL)
    {
        A->right = r.first;
        return make_pair(A,r.second);
    }
    if(A->right==NULL)
    {
        A->right=l.first;
        A->left=NULL;
        return make_pair(A,l.second);
    }
    
    A->right=l.first;
    A->left=NULL;
    (l.second)->right=r.first;
    
    return make_pair(A,r.second);
}
 
 
TreeNode* Solution::flatten(TreeNode* A) {
    
    return ( flat(A).first);
    
}

