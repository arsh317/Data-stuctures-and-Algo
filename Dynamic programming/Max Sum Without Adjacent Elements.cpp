/* 

Max Sum Without Adjacent Elements
Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it. Note: You can choose more than 2 numbers.

*/

int Solution::adjacent(vector<vector<int> > &A) {
    
    int n=A[0].size();
    
    int ans[n]; memset(ans,0,sizeof(ans));
    ans[0]=max(A[0][0],A[1][0]);
    
    if(n<2){ return ans[0]; }
    ans[1]=max(ans[0],max(A[0][1],A[1][1]));
    
    for(int i=2; i<n; i++)
    {
        ans[i]=max( (max(A[0][i],A[1][i])+ans[i-2] ) , ans[i-1] );
    }
    
    return ans[n-1];
}
