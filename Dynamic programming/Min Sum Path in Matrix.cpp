/* 

Min Sum Path in Matrix
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

*/


int Solution::minPathSum(vector<vector<int> > &A) {
    
    int n=A.size(),m=A[0].size();
    
    int ans[n][m]; memset(ans,0,sizeof(ans));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==0 && j==0){ ans[i][j]=A[i][j]; continue; }
            if(i==0){ ans[i][j]=A[i][j]+ans[i][j-1]; continue; }
            if(j==0){ ans[i][j]=A[i][j]+ans[i-1][j]; continue; }
            
            ans[i][j]=A[i][j]+min(ans[i-1][j],ans[i][j-1]);
        }
    }
    
    return ans[n-1][m-1];
}
