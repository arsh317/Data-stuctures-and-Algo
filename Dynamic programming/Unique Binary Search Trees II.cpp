/* 

Unique Binary Search Trees II
Given an integer A, how many structurally unique BST's (binary search trees) exist that can store values 1...A? 

*/

int Solution::numTrees(int A) {
    
    if(A<=1){ return 1; }
    
    vector<int> ans(A+1,0);
    ans[0]=ans[1]=1;
    
    for(int i=2; i<=A; i++)
    {
        ans[i]=0;
        for(int j=0; j<i; j++)
        {
            ans[i]+=ans[j]*ans[i-j-1];
        }
    }
    
    return ans[A];
}