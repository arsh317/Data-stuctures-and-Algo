/* 
Sum binary tree or not
Given a binary tree. Check whether the given tree is a Sum-binary tree or not. SumTree is a Binary Tree 
where the value of a node is equal to sum of the nodes present in its
left subtree and right subtree. An empty tree is SumTree and sum of an empty tree can be considered as 0. 
A leaf node is also considered as SumTree. */


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int help(TreeNode* A)
{
    if(A==NULL){ return 0; }
    if(A->left==NULL && A->right==NULL){ return (A->val); }
    
    int l=help(A->left);
    int r=help(A->right);
    
    if(l<0 || r<0){ return -1; }
    if(l+r == A->val){ return (2*(A->val)); }
    return -1;
}
int Solution::solve(TreeNode* A) {
    
    int h=help(A);
    if(h<0){ return 0; }
    return 1;
}
