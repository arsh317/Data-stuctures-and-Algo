/* 
Identical Binary Trees
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem Example :
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
    int l=solve(A->left,B->left);
    int r=solve(A->right,B->right);
    
    return (l&r);
}

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    
    return solve(A,B);
}
