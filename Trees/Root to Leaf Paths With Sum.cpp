/* 
Root to Leaf Paths With Sum
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum. 
For example: Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
 
void help(TreeNode* A,int B,int sum,vector<vector<int> > &ans,vector<int> &vt)
{
    if(A==NULL){ return; }
    if(A->left==NULL && A->right==NULL)
    { 
       sum+=(A->val); vt.push_back(A->val);
       if(sum==B) ans.push_back(vt); vt.pop_back();
        return;
    }
    
    sum+=(A->val); vt.push_back(A->val);
    help(A->left,B,sum,ans,vt);
    help(A->right,B,sum,ans,vt);
    vt.pop_back();
} 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    
    vector<vector<int> > ans; vector<int> vt;
    help(A,B,0,ans,vt);
    
    return ans;
}
