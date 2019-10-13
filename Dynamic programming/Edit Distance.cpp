/* 
Edit Distance
Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.) You have the following 3 operations permitted on a word:
Insert a character
Delete a character
Replace a character

*/

int Solution::minDistance(string A, string B) {
    
    int n=A.size(),m=B.size();
    
    vector<vector<int>> ans(n+1,vector<int>(m+1,0));
    //int ans[n+1][m+1]; memset(ans,0,sizeof(ans));
    
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i==0 && j==0){ ans[i][j]=0; continue; }
            if(i==0){ ans[i][j]=j; continue; }
            if(j==0){ ans[i][j]=i; continue; }
            
            if(A[i-1]==B[j-1]){  ans[i][j]=ans[i-1][j-1];  }
            else
            {
                //cout<<i<<" : "<<j<<endl;
                int r=1+ans[i-1][j-1];
                int in=1+ans[i][j-1];
                int d=1+ans[i-1][j];
                
                ans[i][j]=min(r,min(in,d));
            }
        }
    }
    
    //cout<<"reached"<<endl;
    return ans[n][m];
}
