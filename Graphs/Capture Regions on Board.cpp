/* 

Capture Regions on Board
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'. A region is captured by flipping all 'O's into 'X's in that surrounded region

*/

void dfs(int i, int j,vector<vector<char> > &A)
{
    A[i][j]='a';
    int n=A.size(),m=A[0].size();
    
    if(i-1>=0 && A[i-1][j]=='O'){ dfs(i-1,j,A);  }
    if(i+1 <n && A[i+1][j]=='O'){ dfs(i+1,j,A);  }
    if(j-1>=0 && A[i][j-1]=='O'){ dfs(i,j-1,A);  }
    if(j+1 <m && A[i][j+1]=='O'){ dfs(i,j+1,A);  }
}

void Solution::solve(vector<vector<char> > &A) {
    
    int n=A.size(),m=A[0].size();
   
    for(int j=0; j<m; j++)
    { 
        if(A[0][j]=='O'){ dfs(0,j,A);   }
        if(A[n-1][j]=='O'){ dfs(n-1,j,A);   }
    }
    
    for(int i=0; i<n; i++)
    { 
        if(A[i][0]=='O'){ dfs(i,0,A);   }
        if(A[i][m-1]=='O'){ dfs(i,m-1,A);   }
    }
    
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(A[i][j]=='O') { A[i][j]='X'; }
        }
    }
    
     for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(A[i][j]=='a') { A[i][j]='O'; }
        }
    }
    
}
