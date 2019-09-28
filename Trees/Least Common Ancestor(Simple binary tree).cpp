/* 
Least Common Ancestor
Find the lowest common ancestor in an unordered binary tree given two values in the tree.

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
char ch; 
int lca_hl(TreeNode* A, int B, int C,int &ct)
{
    if(A==NULL){  return -1; }
    
    int l=lca_hl(A->left,B,C,ct);
    int r=lca_hl(A->right,B,C,ct);
    
    if((A->val)==B || (A->val)==C ){ ct++; return (A->val);  }
    
    if(l==-1){ return r; }
    if(r==-1){ return l; }
    
    if(l!=-1 && r!=-1){ return (A->val); }
}
int Solution::lca(TreeNode* A, int B, int C) {
   
    int ct=0;
    int ans=lca_hl(A,B,C,ct);
    
    if(B!=C && ct<2){ return -1; }
    return ans;
}