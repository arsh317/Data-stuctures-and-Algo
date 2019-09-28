/* 
BST Iterator
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST. 
The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest 
number in the BST, and so on.
Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. 
Try to optimize the additional space complexity apart from the amortized time complexity.
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
stack<TreeNode*> st;
BSTIterator::BSTIterator(TreeNode *root) {
    
    while(!st.empty()){ st.pop(); }
    TreeNode *rt=root;
    while(rt!=NULL)
    { st.push(rt); rt=rt->left; }
    

}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(st.empty()){ return false; }
    return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    
    TreeNode *t=st.top(),*r; st.pop();
    r=t->right; 
    while(r!=NULL){ st.push(r); r=r->left; }
    
    return (t->val);

}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
