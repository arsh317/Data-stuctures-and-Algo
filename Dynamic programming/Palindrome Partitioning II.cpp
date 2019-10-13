/* 

Palindrome Partitioning II
Given a string A, partition A such that every substring of the partition is a palindrome. Return the minimum cuts needed for a palindrome partitioning of A.

*/


iint Solution::minCut(string A) {
    
    int n=A.size(); 
    vector<vector<bool>> pal(n,vector<bool>(n,false));
    vector<vector<int>> ans(n,vector<int>(n,0));
    
    for(int j=0; j<n; j++)
    {
        for(int i=j; i>=0; i--)
        {
            if(i==j){ pal[i][j]=1; continue; }
            
            if(A[i]==A[j] && j-i==1){ pal[i][j]=1; }
            else if(A[i]==A[j]){ pal[i][j]=pal[i+1][j-1]; }
            else{ pal[i][j]=0; }
        }
    }
    
    for(int j=0; j<n; j++)
    {
        for(int i=j; i>=0; i--)
        {
            if(pal[i][j]){ ans[i][j]=0;  continue; }
            
            int mn=INT_MAX;
            for(int k=i; k<j; k++)
            {
                mn=min(mn,1+ans[i][k]+ans[k+1][j]);
            }
            ans[i][j]=mn;
        }
    }
    
    return ans[0][n-1];
}
