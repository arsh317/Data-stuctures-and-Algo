/* 

Rotten Oranges
Given a matrix of integers A of size N x M consisting of 0, 1 or 2. Each cell can have three values:
The value 0 representing an empty cell.
The value 1 representing a fresh orange.
The value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (Left, Right, Top, or Bottom) to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange.
If this is impossible, return -1 instead.

*/

int Solution::solve(vector<vector<int> > &A) {
    
    int n=A.size(),m=A[0].size();
    
    queue< pair<pair<int,int>,int> > q;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(A[i][j]==2) 
            {    q.push({{i,j},0});        }
        }
    }
    
    int mx=0;
    while(!q.empty())
    {
        pair<pair<int,int>,int> p=q.front(); q.pop();
        
        int i=p.first.first;
        int j=p.first.second;
        int lv=p.second;
        
        mx=max(mx,lv);
        
        if(i-1>=0 && A[i-1][j]==1){ A[i-1][j]=2;  q.push({ {i-1,j},lv+1 });  }
        if(i+1 <n && A[i+1][j]==1){ A[i+1][j]=2;  q.push({ {i+1,j},lv+1 });  }
        if(j-1>=0 && A[i][j-1]==1){ A[i][j-1]=2;  q.push({ {i,j-1},lv+1 });  }
        if(j+1 <m && A[i][j+1]==1){ A[i][j+1]=2;  q.push({ {i,j+1},lv+1 });  }
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(A[i][j]==1) { return -1; }
        }
    }
    
    return mx;
    
}
