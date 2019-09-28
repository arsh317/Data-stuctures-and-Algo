/* 
Recover Binary Search Tree
Two elements of a binary search tree (BST) are swapped by mistake. Tell us the 2 values swapping which the tree will be restored.
 Note: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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

void morrtrv(TreeNode* A,vector<int> &vt)
{
    TreeNode* curr= A,*prev=NULL;
    
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
           if(prev!=NULL && prev->val > curr->val){ vt.push_back(prev->val); vt.push_back(curr->val); }
           prev=curr; curr=curr->right;
        }
        else
        {
            TreeNode* pre=curr->left;
            while(pre->right!=NULL && pre->right!=curr)
            { pre=pre->right; }
            
            if(pre->right==NULL){ pre->right=curr; curr=curr->left; }
            else
            {
                pre->right=NULL;
                if(prev!=NULL && prev->val > curr->val){ vt.push_back(prev->val); vt.push_back(curr->val); }
                prev=curr; 
                curr=curr->right;
            }
        }
    }
}
vector<int> Solution::recoverTree(TreeNode* A) {
    
    vector<int> vt;
    morrtrv(A,vt);
    
    int mn=vt[0],mx=vt[0];
    for(int i=0; i<vt.size(); i++)
    {  mn=min(mn,vt[i]); mx=max(mx,vt[i]);   }
    
    
    vt[0]=mn; vt[1]=mx;
    while(vt.size()>2){ vt.pop_back(); }
    
    
    return vt;
}
