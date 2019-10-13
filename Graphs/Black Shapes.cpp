/* 

Black Shapes
Given N x M character matrix A of O's and X's, where O = white, X = black.
Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

*/



void dfs(int i, int j,vector<string> &A)
{
    A[i][j]='O';
    int n=A.size(),m=A[0].size();
    
    if(i-1>=0 && A[i-1][j]=='X'){ dfs(i-1,j,A);  }
    if(i+1 <n && A[i+1][j]=='X'){ dfs(i+1,j,A);  }
    if(j-1>=0 && A[i][j-1]=='X'){ dfs(i,j-1,A);  }
    if(j+1 <m && A[i][j+1]=='X'){ dfs(i,j+1,A);  }
}

int Solution::black(vector<string> &A) {
    
    int ct=0;
    for(int i=0; i<A.size(); i++)
    {
        for(int j=0; j<A[0].size(); j++)
        {
            if(A[i][j]=='X'){ ct++; dfs(i,j,A); }
        }
    }
    return ct;
}
