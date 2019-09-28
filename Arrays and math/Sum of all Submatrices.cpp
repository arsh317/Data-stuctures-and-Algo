/*
Sum of all Submatrices
Given a 2D Matrix of dimensions N*N, we need to return sum of all possible submatrices.
*/
int Solution::solve(vector<vector<int> > &A) {
    
    if(A.size()==0){ return 0; }
    
    int n=A.size();
    int sum=0;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int c1=(i+1)*(j+1);
            int c2=(n-i)*(n-j);
            
            sum+=c1*c2*A[i][j];
        }
    }
    
    return sum;
}
