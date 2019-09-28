/* 
Vertical Order traversal of Binary Tree
Given a binary tree, return a 2-D array with vertical order traversal of it. Go through the example and image for more details.  Example : Given binary tree:
      6
    /   \
   3     7
  / \     \
 2   5     9
returns
[
    [2],
    [3],
    [6 5],
    [7],
    [9]
]

*/

/*
Definition for binary tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
   
    vector<vector<int> > vt;
    if(A==NULL){ return vt; }
    unordered_map<int,vector<int> > mp;
    
    queue<pair<TreeNode*,int>> qt;
    qt.push(make_pair(A,0));
    int min=0,max=0;
    
    while(!qt.empty())
    {
        TreeNode* t=qt.front().first; int p=qt.front().second;
        mp[p].push_back(t->val);
        if(p< min){ min=p; }
        if(p> max){ max=p; }
        if(t->left!=NULL){ qt.push(make_pair(t->left,p-1)); }
        if(t->right!=NULL){ qt.push(make_pair(t->right,p+1)); }
        
        qt.pop();

    }
    
    for(int i=min; i<=max; i++)
    {
        vt.push_back(mp[i]);
    }
    
    return vt;
    
}
