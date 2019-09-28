/* 
Check if given Preorder, Inorder and Postorder traversals are of same tree
Given 3 array of integers A, B and C. A represents preorder traversal of a binary tree. 
B represents inorder traversal of a binary tree. C represents postorder traversal of a binary tree. 
Check whether these tree traversals are of the same tree or not. If they are of same tree return 1 else return 0
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

void preorder(TreeNode* rt,vector<int> &B)
{
    if(rt==NULL){ return; }
    
    B.push_back(rt->val);
    preorder(rt->left,B);
    preorder(rt->right,B);
}

int check(vector<int> &A,vector<int> &B)
{
    for(int i=0; i<A.size(); i++)
    { if(A[i]!=B[i]) { return 0; }   }
    
    return 1;
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    unordered_map<int,int> mp; int ptr=C.size()-1;
    for(int i=0; i<B.size(); i++){ mp[B[i]]=i; }
    
    TreeNode* root =build(B,C,0,B.size()-1,ptr,mp);
    
    vector<int> vt;
    preorder(root,vt);
    
    return check(A,vt);
    
    
}
