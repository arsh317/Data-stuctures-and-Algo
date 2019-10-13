/* 

Interleaving Strings
Given A, B, C, find whether C is formed by the interleaving of A and B. Input Format:*
The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.

*/

int Solution::isInterleave(string A, string B, string C) {
    
    
    int n=A.size(),m=B.size();
    if(n+m != C.size()){ return 0; }
    
    vector<vector<bool>> ans(n+1,vector<bool>(m+1,false));
    
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i==0 && j==0){ ans[i][j]=1; continue; } 
            
            if(i==0)
            { ans[i][j]=(B[j-1]==C[j-1])&&(ans[i][j-1]); continue; }
            
            if(j==0){  ans[i][j]=(A[i-1]==C[i-1])&&(ans[i-1][j]); continue; }
            
            if(A[i-1]!=C[i+j-1] && B[j-1]!=C[i+j-1])//when none of the last char of two string matches last of target string
            {  ans[i][j]=0;  }
            
            else if(A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1])
            {  ans[i][j]=ans[i-1][j] || ans[i][j-1]; }
            
            else if(A[i-1]==C[i+j-1])
            {  ans[i][j]=ans[i-1][j];  }
            
            else if(B[j-1]==C[i+j-1])
            {  ans[i][j]=ans[i][j-1];  }
            
        }
    }
   
    return ans[n][m];
}