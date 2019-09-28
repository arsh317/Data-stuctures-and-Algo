/* 
Inorder Traversal of Cartesian Tree
Given an inorder traversal of a cartesian tree, construct the tree.
 Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. Note: You may assume that duplicates do not exist in the tree. 

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



int getmax(vector<int> &A,int st,int en)
{
    int mxin=st;
    for(int i=st; i<=en; i++)
    {
        if(A[i]>A[mxin]){ mxin=i; }
    }
    return mxin;
}
TreeNode* build(vector<int> &A,int st,int en)
{
    if(st>en){ return NULL; }
    
    int mxin=getmax(A,st,en);
    TreeNode *root=new TreeNode(A[mxin]);
    
    root->left=build(A,st,mxin-1);
    root->right=build(A,mxin+1,en);
    
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> &A) {
    
    return build(A,0,A.size()-1);
}
