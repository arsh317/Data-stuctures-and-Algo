/* 
Sum Root to Leaf Numbers
Given a binary tree containing digits from 0-9 only,each root-to-leaf path could represent a number. 
An example is the root-to-leaf path 1->2->3 which represents the number 123. Find the total sum of 
all root-to-leaf numbers % 1003. Example :
    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12. The root-to-leaf path 1->3 represents the number 13.
 Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.
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
void help(TreeNode* A,int sum,int &ans)
{
    if(A==NULL){ return; }
    if(A->left==NULL && A->right==NULL)
    { 
        sum=sum*10+(A->val); sum%=1003; ans+=sum;  ans%=1003;   // sum/=10;
        return;
    }
    
    sum=sum*10+(A->val); sum%=1003;
    help(A->left,sum,ans);
    help(A->right,sum,ans);
    //sum/=10;
}
int Solution::sumNumbers(TreeNode* A) {
    int sum=0,ans=0;
    help(A,sum,ans);
    
    return ans;
}
