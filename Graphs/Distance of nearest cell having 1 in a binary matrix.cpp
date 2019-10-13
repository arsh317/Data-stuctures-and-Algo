/* 

Distance of nearest cell having 1 in a binary matrix
Given a matrix of integers A of size N x M consisting of 0 or 1. For each cell of the matrix find the distance of nearest 1 in the matrix. Distance between two cells (x1, y1) and (x2, y2) is defined as |x1 - y1| + |x2 - y2|. Find and return a matrix B of size N x M which defines for each cell in A distance of nearest 1 in the matrix A. Note:
Your solution will run on multiple test cases. If you are using global variables, make sure to clear them.
There is atleast one 1 is present in the matrix.

*/

vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    
    int n=A.size(),m=A[0].size();
    
    vector<vector<int> > ans(n,vector<int>(m,0));
    
    queue< pair<pair<int,int>,int> > q;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(A[i][j]==1) 
            {    q.push({{i,j},0});        }
        }
    }
    
    while(!q.empty())
    {
        pair<pair<int,int>,int> p=q.front(); q.pop();
        
        int i=p.first.first;
        int j=p.first.second;
        int lv=p.second;
        
        ans[i][j]=lv;
      
        if(i-1>=0 && A[i-1][j]==0){ A[i-1][j]=1;  q.push({ {i-1,j},lv+1 });  }
        if(i+1 <n && A[i+1][j]==0){ A[i+1][j]=1;  q.push({ {i+1,j},lv+1 });  }
        if(j-1>=0 && A[i][j-1]==0){ A[i][j-1]=1;  q.push({ {i,j-1},lv+1 });  }
        if(j+1 <m && A[i][j+1]==0){ A[i][j+1]=1;  q.push({ {i,j+1},lv+1 });  }
    }
    
    return ans;
    

}
