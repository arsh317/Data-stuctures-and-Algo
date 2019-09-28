/* 
Convert a binary tree to a circular doubly linked list
Given a binary tree convert it into circular doubly linked list based on the following rules:
The left and right pointers in nodes are to be used as previous and next pointers respectively in converted Circular Linked List.
The order of nodes in List must be same as Inorder of the given Binary Tree.
The first node of Inorder traversal must be the head node of the Circular List.
NOTE:
You are expected to convert the binary tree into Doubly linked list in place.
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

TreeNode* concat(TreeNode* A,TreeNode* B)
{
    if(A==NULL){ return B; }
    if(B==NULL){ return A; }
    TreeNode* Al=A->left,*Bl=B->left;
    Al->right=B; B->left=Al;
    A->left=Bl; Bl->right=A;
    
    return A;
}

TreeNode* convert(TreeNode *A)
{
   if(A==NULL){ return NULL; }
   TreeNode *lf=convert(A->left);
   TreeNode *rt=convert(A->right);
   
   A->right=A->left=A;
   return ( concat(concat(lf,A),rt) );
}

TreeNode* solve(TreeNode *A){
    
    return convert(A);

}
