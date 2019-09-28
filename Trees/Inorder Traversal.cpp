/* 
Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values. Example : Given binary tree
   1
    \
     2
    /
   3
return [1,3,2]. Using recursion is not allowed.

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
 
void inorder(TreeNode* A,vector<int> &vt)
{
    if(A==NULL){ return; }
    inorder(A->left,vt);
    vt.push_back(A->val);
    inorder(A->right,vt);
} 
vector<int> Solution::inorderTraversal(TreeNode* A) {
    
    vector<int> vt;
    //inorder(A,vt);
    stack<TreeNode*> st;
    TreeNode* curr=A;
    st.push(curr); curr=curr->left;
    while(!st.empty() || curr!=NULL)
    {
        if(curr!=NULL){ st.push(curr); curr=curr->left; }
        else
        {
            vt.push_back(st.top()->val); curr=st.top()->right; st.pop();
        }
    }
    
    return vt;
}
