/* 
ZigZag Level Order Traversal BT
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between). 
Example : Given binary tree
    3
   / \
  9  20
    /  \
   15   7
return
[
         [3],
         [20, 9],
         [15, 7]
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
void  rev(vector<int> &A)
{
    int l=A.size();
    for(int i=0; i<=l/2-1; i++)
    { int t=A[i]; A[i]=A[l-i-1]; A[l-i-1]=t; }
}
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    
    vector<vector<int> > ans; 
    if(A==NULL){ return ans; }
    
    queue<TreeNode*> qt; 
    qt.push(A);   int n1=1,n2=0,lv=0;
    while(!qt.empty())
    {
        vector<int> vt;
        while(n1--)
        {
            TreeNode* t=qt.front(); 
            if(t->left!=NULL){  n2++; qt.push(t->left); }
            if(t->right!=NULL){ n2++; qt.push(t->right); }
            vt.push_back(t->val); qt.pop();
        }
        if(lv%2==1){ rev(vt); }
        ans.push_back(vt);
        n1=n2; n2=0;
        lv++;
    }
    
}
