/* 

Regular Expression Match
Implement wildcard pattern matching with support for '?' and '*' for strings A and B.
'?' : Matches any single character.
'*' : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

*/

int Solution::isMatch(const string A, const string B) {
    
    int n=A.size(),m=B.size();
    
    vector<vector<bool>> ans(n+1,vector<bool>(m+1,false));
    ///int ans[n+1][m+1]; memset(ans,0,sizeof(ans));
    
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i==0 && j==0){ ans[i][j]=1; continue; } //when both the string and pattern are empty(Its a match)
            
            if(i==0)//When string is empty. All the remaining pattern chars should be '*' for  a match
            { ans[i][j]=(B[j-1]=='*')&&(ans[i][j-1]); continue; }
            
            if(j==0){ ans[i][j]=0; continue; }// when pattern is empty but string is not(Mismatch)
            
            if(B[j-1]!='*' && B[j-1]!='?')//when pattern char is lowercase
            {  ans[i][j]= (A[i-1]==B[j-1])&&(ans[i-1][j-1]);  }
            else
            {
                if(B[j-1]=='?')
                {   ans[i][j]=ans[i-1][j-1];  }
                
                else
                {
                    ans[i][j]=ans[i][j-1] || ans[i-1][j];
                }
            }
        }
    }
   
    return ans[n][m];
}
