/* 
Common Nodes in Two Binary Search Trees
Given two BSTs, return the sum of all common nodes in both. In case there is no common node, return 0 NOTE
1. Your code will run on multiple test cases, please come up with an optimised solution.
2. Try to do it one pass through the trees.
INPUT FORMAT
A : Root of Tree A
B : Root of Tree B
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

int Solution::solve(TreeNode* A, TreeNode* B) {
    
    TreeNode *curr1=A,*curr2=B; stack<TreeNode*> st1,st2;  int sum=0;
    while(curr1!=NULL){ st1.push(curr1); curr1=curr1->left; }
    while(curr2!=NULL){ st2.push(curr2); curr2=curr2->left; }
    
    while(!st1.empty() && !st2.empty())
    {
        TreeNode *t1=st1.top(),*t2=st2.top();
        if(t1->val==t2->val)
        {
            sum+=t1->val;
            TreeNode *t=t1->right;
            st1.pop(); st2.pop(); 
            while(t!=NULL){ st1.push(t); t=t->left; }
            t=t2->right;
            while(t!=NULL){ st2.push(t); t=t->left; }
        }
        else if(t1->val < t2->val)
        {
            TreeNode *t=t1->right;
            st1.pop(); 
            while(t!=NULL){ st1.push(t); t=t->left; }
        }
        else
        {
            TreeNode *t=t2->right;
            st2.pop(); 
            while(t!=NULL){ st2.push(t); t=t->left; }
        }
    }
    
    return sum;
}
