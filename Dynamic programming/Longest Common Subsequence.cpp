/* 

Longest Common Subsequence
Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings. You need to return the length of such longest common subsequence

*/

int Solution::solve(string A, string B) {
    
    int n=A.size(),m=B.size();
    
    int ans[n][m]; memset(ans,0,sizeof(ans));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==0 && j==0)
            {
                if(A[i]==B[j]){ ans[i][j]=1; }
                else{ ans[i][j]=0; }
                continue;
            }
            
            if(i==0)
            {
                if(A[i]==B[j]){ ans[i][j]=1; }
                else{ ans[i][j]=ans[i][j-1]; }
                continue;
            }
            
            if(j==0)
            {
                if(A[i]==B[j]){ ans[i][j]=1; }
                else{ ans[i][j]=ans[i-1][j]; }
                continue;
            }
            
            if(A[i]==B[j]){ ans[i][j]=1+ans[i-1][j-1]; }
            else{ ans[i][j]=max(ans[i-1][j],ans[i][j-1]);  }
        }
    }
    
    return ans[n-1][m-1];
}

