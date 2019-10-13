/* 

Burst Balloons
You are given N ballons each with a number of coins associated with them. An array of integers A represents the coins associated with the ith ballon. You are asked to burst all the balloons. If the you burst balloon ith you will get A[left] * A[i] * A[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent. Find the maximum coins you can collect by bursting the balloons wisely. Note:
You may imagine A[-1] = A[n] = 1. They are not real therefore you can not burst them.
Your submission will run on multiple test cases if you are using global make sure to clear them.

*/

int Solution::solve(vector<int> &A) {
    
    int n=A.size();
    
    vector<vector<int>> ans(n,vector<int>(n,0));
    
    for(int j=0; j<n; j++)
    {
        for(int i=j; i>=0; i--)
        {
            int l=1,r=1;
            if(i>0){ l=A[i-1]; }
            if(j<n-1){ r=A[j+1]; }
            
            if(i==j){ ans[i][j]=l*A[i]*r; continue; }
            
            int mx=0;
            for(int k=i; k<=j; k++)
            {
                if(k==i){ mx=max(mx,ans[k+1][j]+l*A[k]*r); }
                else if(k==j){  mx=max(mx,ans[i][k-1]+l*A[k]*r);  }
                else
                {
                    mx=max(mx,ans[i][k-1]+ans[k+1][j]+l*A[k]*r); 
                }
            }
            
            ans[i][j]=mx;
        }
    }
    
    return ans[0][n-1];
}
