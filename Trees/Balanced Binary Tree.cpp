/* 
Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.
Height-balanced binary tree : is defined as a binary tree in which 
the depth of the two subtrees of every node never differ by more than 1.
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
int height(TreeNode* A)
{
    if(A==NULL){ return 0; }
    int l=height(A->left);
    int r=height(A->right);
    
    if(l<0 || r<0){ return -1; }
    if( abs(l-r)>1 ){ return -1; }
    
    return ( max(l,r)+1 );
}
 
int Solution::isBalanced(TreeNode* A)
{
    int h=height(A);
    if(h<0){ return 0; }
    return 1;
}