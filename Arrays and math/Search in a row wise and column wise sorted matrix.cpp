/*
Search in a row wise and column wise sorted matrix
Given a matrix of integers A of size N x M and an integer B.

In the given matrix every row and column is sorted in increasing order.

Find and return the position of B in the matrix in the given form:
*/

int Solution::solve(vector<vector<int> > &A, int B) {
    
    int i=0,j=A[0].size()-1;
    
    while(i<A.size() && j>=0)
    {
        if(A[i][j]==B){ return ((i+1)*1009+(j+1)); }
        else if(B<A[i][j]){ j--; }
        else{ i++; }
    }
    
    return -1;
    
}
