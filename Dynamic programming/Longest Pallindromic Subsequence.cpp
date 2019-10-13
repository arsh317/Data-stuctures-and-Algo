/* 

Longest Pallindromic Subsequence
Given a strings A. Find the common pallindromic sequence ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself You need to return the length of such longest common subsequence

*/

int Solution::solve(string A) {
    
    int n=A.size();
    
    int ans[n][n]; memset(ans,0,sizeof(ans));
    
    for(int j=0; j<n; j++)
    {
        for(int i=j; i>=0; i--)
        {
            if(i>j){ ans[i][j]=0; continue; }
            if(i==j){ ans[i][j]=1; continue; }
            
            if(A[i]==A[j]){ ans[i][j]=2+ans[i+1][j-1]; }
            else{ ans[i][j]=max(ans[i+1][j],ans[i][j-1]); }
        }
    }
    
    return ans[0][n-1];
}
