/* 
Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values. Example : Given binary tree
   1
    \
     2
    /
   3
return [3,2,1]. Using recursion is not allowed.
[1,3,2]. Using recursion is not allowed.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void postorder(TreeNode* A,vector<int> &vt)
{
    if(A==NULL){ return; }
    postorder(A->left,vt);
    postorder(A->right,vt);
    vt.push_back(A->val);
}
vector<int> Solution::postorderTraversal(TreeNode* A) {
    
    vector<int> vt;
    postorder(A,vt);
    
    return vt;
}
