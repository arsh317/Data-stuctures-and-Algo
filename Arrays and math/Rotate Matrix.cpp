/*
Rotate Matrix
You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees 
(clockwise). You need to do this in place. Note that if you end up using an additional array, 
you will only receive partial score.
*/
void Solution::rotate(vector<vector<int> > &A) {
    int t1,t2;
    int n=A.size();
    for(int i=0; i<n/2; i++ )
    {
        for(int j=i; j<n-i-1; j++)
        {
            int x1=i,y1=j;
            int x,y;
            x=y1; y=n-x1-1;
            t1=A[x][y];
            A[x][y]=A[i][j];
            
            x1=x; y1=y;
            x=y1; y=n-x1-1;
            t2=A[x][y];
            A[x][y]=t1;
            
            x1=x; y1=y;
            x=y1; y=n-x1-1;
            t1=A[x][y];
            A[x][y]=t2;
            
            x1=x; y1=y;
            x=y1; y=n-x1-1;
            A[x][y]=t1;
        }
    }
}
