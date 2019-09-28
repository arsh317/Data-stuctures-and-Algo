/* 
Binary Tree From Inorder And Postorder
Given inorder and postorder traversal of a tree, construct the binary tree.
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
TreeNode* build (vector<int> &in,vector<int> &pos,int ins,int ine,int &posptr,unordered_map<int,int> &mp)
{
    if(ins>ine || posptr<0){ return NULL; }
    
    int rtval=pos[posptr];  posptr--;
    TreeNode* root=new TreeNode(rtval);
    
    root->right=build(in,pos,mp[rtval]+1,ine,posptr,mp);
    root->left=build(in,pos,ins,mp[rtval]-1,posptr,mp);
    
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    unordered_map<int,int> mp; int ptr=B.size()-1;
    for(int i=0; i<A.size(); i++){ mp[A[i]]=i; }
    
    return build(A,B,0,A.size()-1,ptr,mp);
    
}
