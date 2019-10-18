/* 

Palindrome Partitioning II
Given a string A, partition A such that every substring of the partition is a palindrome. Return the minimum cuts needed for a palindrome partitioning of A.

*/


int Solution::minCut(string A) {
    
    int n=A.size(); 
        vector<vector<bool>> pal(n,vector<bool>(n,false));
        vector<int> ans(n,0);

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

        for(int i=n-1; i>=0; i--)
        {
        
            int mn=INT_MAX;
            for(int j=i; j<n; j++)
            {
                if(j==n-1 && pal[i][j]){ mn=0; continue; }
                if(pal[i][j]){ mn=min(mn,1+ans[j+1]); }        
            }
            ans[i]=mn;

        }

        return ans[0];
}
