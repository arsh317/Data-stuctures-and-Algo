/* 
Sorted Array To Balanced BST
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
TreeNode* build(const vector<int> &A,int st,int en) 
{
    if(st>en){ return NULL; }
    int mid=st+(en-st)/2;
    TreeNode* root=new TreeNode(A[mid]);
    
    root->left=build(A,st,mid-1);
    root->right=build(A,mid+1,en);
    
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    
   return build(A,0,A.size()-1);
}
