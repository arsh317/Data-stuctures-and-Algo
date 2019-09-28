/* 
Print all root to leaf paths
You are given a binary tree. Find all paths from root to leaves of the binary tree. 
Input Format
The only argument given is the root pointer of tree A.
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
void help(TreeNode* A,vector<vector<int> > &ans, vector<int> &vt)
{
    if(A==NULL){ return; }
    if(A->left==NULL && A->right==NULL){ vt.push_back(A->val); ans.push_back(vt); vt.pop_back(); return; }
    
    vt.push_back(A->val);
    help(A->left,ans,vt);
    help(A->right,ans,vt);
    vt.pop_back();
}

vector<vector<int> > Solution::solve(TreeNode* A) {
    
    vector<vector<int> > ans; vector<int> vt;
    help(A,ans,vt);
    
    return ans;
}
