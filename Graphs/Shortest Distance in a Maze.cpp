/* 

Shortest Distance in a Maze
Given a matrix of integers A of size N x M describing a maze. The maze consists of empty locations and walls. 1 represents a wall in a matrix and 0 represents an empty location in a wall. There is a ball trapped in a maze. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction. Given two array of integers of size B and C of size 2 denoting the starting and destination position of the ball. Find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the starting position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1. Note:
Rows are numbered from top to bottom and columns are numbered from left to right.
Assume the border of the maze are all walls.
Both the starting position of the ball and the destination position of the ball exist on an empty space.
Both the starting and destination positions will not be at the same position initially.

*/



struct node
{
    int i,j,lv;
    char pr;
    
    node(int a,int b, int c,char ch)
    { i=a; j=b; lv=c; pr=ch; }
};

int Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C) {
    
    int n=A.size(),m=A[0].size();
    
    vector<vector<int> > ans(n,vector<int>(m,0));
    
    queue< node > q;
    node x(B[0],B[1],0,'s'); q.push(x);
    
    while(!q.empty())
    {
        node p=q.front(); q.pop();
        int i=p.i;
        int j=p.j;
        int lv=p.lv;
        char pr=p.pr;
        
        ans[i][j]=lv;
        
        int dc=0; 
        
        if(pr=='s'){ dc=1; }
        else if(pr=='r' && (j-1<0 || A[i][j-1]==1)){ dc=1;  }
        else if(pr=='l' && (j+1>=m || A[i][j+1]==1)){ dc=1;  }
        else if(pr=='t' && (i+1>=n || A[i+1][j]==1)){ dc=1; }
        else if(pr=='d' && (i-1<0 || A[i-1][j]==1)){ dc=1; }
        else{ dc=0; }
        
        if(dc==0)
        {
            if(pr=='r' && A[i][j-1]!=2){ node t(i,j-1,lv+1,'r'); q.push(t);  }
            if(pr=='l' && A[i][j+1]!=2){ node t(i,j+1,lv+1,'l'); q.push(t);  }
            if(pr=='t' && A[i+1][j]!=2){ node t(i+1,j,lv+1,'t'); q.push(t);  }
            if(pr=='d' && A[i-1][j]!=2){ node t(i-1,j,lv+1,'d'); q.push(t);  }
        }
        else
        {
            A[i][j]=2;
            if(i==C[0] && j==C[1]){ return lv; }
            
            if(i-1>=0 && A[i-1][j]!=1 && A[i-1][j]!=2 && pr!='t'){ node t(i-1,j,lv+1,'d'); q.push(t);  }
            if(i+1 <n && A[i+1][j]!=1 && A[i+1][j]!=2 && pr!='d'){ node t(i+1,j,lv+1,'t'); q.push(t);  }
            if(j-1>=0 && A[i][j-1]!=1 && A[i][j-1]!=2 && pr!='l'){ node t(i,j-1,lv+1,'r'); q.push(t);  }
            if(j+1 <m && A[i][j+1]!=1 && A[i][j+1]!=2 && pr!='r'){ node t(i,j+1,lv+1,'l'); q.push(t);  }
        }
       
    }
    
    return -1;
}
