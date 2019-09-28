/* 
Remove nodes from Path sum less than B
Given a binary tree with root node pointer A and an integer B. 
A complete path is defined as a path from the root to a leaf. 
The sum of all nodes on that path is defined as the sum of that path.
You have to remove (prune the tree) all nodes which don't lie in any path with sum >= B.
Note: A node can be part of multiple paths. 
So we have to delete it only in case when all paths from it have sum less than B. 
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

struct pr
{
    int sm;
    TreeNode* ptr;
    
    pr(int d)
    { sm=d; ptr=NULL; }
};
 
pair<int,TreeNode*> help(TreeNode* A,int &sum, int B)
{
    if(A==NULL){ return make_pair(sum,A); }
    
    sum+=A->val;
    
    pair<int,TreeNode*> l=help(A->left,sum,B);
    pair<int,TreeNode*> r=help(A->right,sum,B);
    
    A->left=l.second;
    A->right=r.second;
    sum-=A->val;
    
    int ans=max(l.first,r.first);
    if(ans<B){ TreeNode* t=A; A=NULL; delete(t); return ( make_pair(ans,A)); }
    else{ return ( make_pair(ans,A)); }
     
}

TreeNode* Solution::solve(TreeNode* A, int B) {
    
    int sum=0;
    return (help(A,sum,B).second);
}
