/* 
Coins in a Line
There are A coins (Assume A is even) in a line. Two players take turns to take a coin from one of the ends of the line until there are no more coins left. The player with the larger amount of money wins. Assume that you go first. Return the maximum amount of money you can win. 
*/


int Solution::maxcoin(vector<int> &A) {
    
    int n=A.size();
    vector<vector<int>> ans(n,vector<int>(n,0));
    
    for(int j=0; j<A.size(); j++)
    {
        for(int i=j; i>=0; i-- )
        {
            if(i==j){ ans[i][j]=A[i]; continue; }
            if(i+1==j){ ans[i][j]=max(A[i],A[j]); continue; }
            
            int x=min(ans[i][j-2],ans[i+1][j-1]);  //i selected coin from right side
            int y=min(ans[i+2][j],ans[i+1][j-1]);  //i selected coin from left side
            
            ans[i][j]=max(x+A[j],y+A[i]);
            
        }
    }
    
    return ans[0][n-1];

}