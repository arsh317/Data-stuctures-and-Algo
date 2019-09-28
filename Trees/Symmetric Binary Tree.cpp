/* 
Symmetric Binary Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
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
 
int solve(TreeNode* A,TreeNode* B)
{
    if(A==NULL && B==NULL){ return 1; }
    if(A==NULL){ return 0; }
    if(B==NULL){ return 0; }
    
    if(A->val!=B->val){ return 0; }
    int l=solve(A->left,B->right);
    int r=solve(A->right,B->left);
    
    return (l&r);
}
int Solution::isSymmetric(TreeNode* A) {
    
    if(A==NULL){ return 1; }
    return solve(A->left,A->right); 
}
