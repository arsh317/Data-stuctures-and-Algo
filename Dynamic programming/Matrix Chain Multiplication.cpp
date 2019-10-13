/* 

Matrix Chain Multiplication
Given an array of integers A representing chain of 2-D matices such that the dimensions of ith matrix is A[i-1] x A[i]. Find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications. Return the minimum number of multiplications needed to multiply the chain

*/


int Solution::solve(vector<int> &A) {
    
    int n=A.size(); 
    vector<vector<int>> ans(n,vector<int>(n,0));
    
    for(int j=1; j<n; j++)
    {
        for(int i=j; i>=1; i--)
        {
            if(i==j){ ans[i][j]=0;  continue; }
            
            int mn=INT_MAX;
            for(int k=i; k<j; k++)
            {
                mn=min(mn,ans[i][k]+ans[k+1][j]+(A[i-1]*A[k]*A[j]) );
            }
            ans[i][j]=mn;
        }
    }
    
    return ans[1][n-1];
}