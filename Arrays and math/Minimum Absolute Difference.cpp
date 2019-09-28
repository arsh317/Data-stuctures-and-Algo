int Solution::solve(vector<int> &A) {
    
    sort(A.begin(),A.end());
    
    int min=A[1]-A[0];
    
    for(int i=1; i<A.size(); i++)
    {
        if(A[i]-A[i-1]< min){  min=A[i]-A[i-1];  }
    }
    
    return min;
}
