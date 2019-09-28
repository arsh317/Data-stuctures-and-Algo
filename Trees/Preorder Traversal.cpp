/* 
Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values. Example : Given binary tree
   1
    \
     2
    /
   3
return [1,2,3]. Using recursion is not allowed.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    
    vector<int> vt;
    if(A==NULL){ return vt; }
    
    stack<TreeNode*> st;
    TreeNode* curr=A;
    
    st.push(A); vt.push_back(A->val); curr=curr->left;
    
    while(!st.empty() || curr!=NULL)
    {
        if(curr!=NULL)
        {   st.push(curr); vt.push_back(curr->val); curr=curr->left;   }
        else
        {
            TreeNode *t=st.top();
            st.pop(); curr=t->right;
        }
    }
    
    return vt;
    
}