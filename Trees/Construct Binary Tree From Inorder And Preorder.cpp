/* 
Construct Binary Tree From Inorder And Preorder
Given preorder and inorder traversal of a tree, construct the binary tree.
 Note: You may assume that duplicates do not exist in the tree. 

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
TreeNode* build (vector<int> &in,vector<int> &pre,int ins,int ine,int &preptr,unordered_map<int,int> &mp)
{
    if(ins>ine || preptr>=pre.size()){ return NULL; }
    
    int rtval=pre[preptr];  preptr++;
    TreeNode* root=new TreeNode(rtval);
    
    root->left=build(in,pre,ins,mp[rtval]-1,preptr,mp);
    root->right=build(in,pre,mp[rtval]+1,ine,preptr,mp);
    
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    unordered_map<int,int> mp; int ptr=0;
    for(int i=0; i<B.size(); i++){ mp[B[i]]=i; }
    
    return build(B,A,0,B.size()-1,ptr,mp);
}
