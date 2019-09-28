/*
Sub-matrix Sum Queries
Given a matrix of integers A of size N x M and multiple queries Q, for each query find 
and return the submatrix sum. Inputs to queries are top left (b, c) and bottom right (d, e) 
indexes of submatrix whose sum is to find out.
*/
vector<int> Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
    
    vector<int> vt;
    //vector<vector<long long int> > B;
    for(int i=0; i<A.size(); i++)
    {
        int sum=0;
        for(int j=0; j<A[0].size(); j++)
        { sum+=A[i][j]; A[i][j]=sum; }
    }
    
    for(int j=0; j<A[0].size(); j++)
    {
        int sum=0;
        for(int i=0; i<A.size(); i++)
        { sum+=A[i][j]; A[i][j]=sum; }
    }
    
    for(int i=0; i<B.size(); i++)
    {
        int i1=B[i]-1,j1=C[i]-1,i2=D[i]-1,j2=E[i]-1;
        int st,sl,sc;
        if(i1-1<0){ st=0; }
        else { st=A[i1-1][j2]; }
        
        if(j1-1<0){ sl=0; }
        else { sl=A[i2][j1-1]; }
        
        if(st==0 || sl==0){ sc=0; }
        else { sc=A[i1-1][j1-1]; }
        
       // cout<<st<<" "<<sl<<" "<<sc<<endl;
        
        
        int sum=A[i2][j2]-st-sl+sc;
        vt.push_back(sum);
    }
    
    return vt;
}
