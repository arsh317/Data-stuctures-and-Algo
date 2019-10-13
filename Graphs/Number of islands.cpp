/* 

Number of islands
Given a matrix of integers A of size N x M consisting of 0 and 1. A group of connected 1's forms an island. From a cell (i, j) such that A[i][j] = 1 you can visit any cell that shares a corner with (i, j) and value in that cell is 1. More formally, from any cell (i, j) if A[i][j] = 1 you can visit:
(i-1, j) if (i-1, j) is inside the matrix and A[i-1][j] = 1.
(i, j-1) if (i, j-1) is inside the matrix and A[i][j-1] = 1.
(i+1, j) if (i+1, j) is inside the matrix and A[i+1][j] = 1.
(i, j+1) if (i, j+1) is inside the matrix and A[i][j+1] = 1.
(i-1, j-1) if (i-1, j-1) is inside the matrix and A[i-1][j-1] = 1.
(i+1, j+1) if (i+1, j+1) is inside the matrix and A[i+1][j+1] = 1.
(i-1, j+1) if (i-1, j+1) is inside the matrix and A[i-1][j+1] = 1.
(i+1, j-1) if (i+1, j-1) is inside the matrix and A[i+1][j-1] = 1.
Return the number of islands. Note:
Rows are numbered from top to bottom and columns are numbered from left to right.

*/




void dfs(int i, int j,vector<vector<int> > &A)
{
    A[i][j]=0;
    int n=A.size(),m=A[0].size();
    
    if(i-1>=0 && A[i-1][j]==1){ dfs(i-1,j,A);  }
    if(i+1 <n && A[i+1][j]==1){ dfs(i+1,j,A);  }
    if(j-1>=0 && A[i][j-1]==1){ dfs(i,j-1,A);  }
    if(j+1 <m && A[i][j+1]==1){ dfs(i,j+1,A);  }
    
    if(i-1>=0 && j-1>=0 && A[i-1][j-1]==1){ dfs(i-1,j-1,A);  }
    if(i+1 <n && j+1 <m && A[i+1][j+1]==1){ dfs(i+1,j+1,A);  }
    if(i+1 <n && j-1>=0 && A[i+1][j-1]==1){ dfs(i+1,j-1,A);  }
    if(i-1>=0 && j+1 <m && A[i-1][j+1]==1){ dfs(i-1,j+1,A);  }
}

int Solution::solve(vector<vector<int> > &A) {
    
    int n=A.size(),m=A[0].size();
    int ct=0;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(A[i][j]==1){ ct++; dfs(i,j,A); }
        }
    }
    
    return ct;
}
