/* 

Length of Longest Fibonacci Subsequence
Given a strictly increasing array A of positive integers forming a sequence, A sequence X1, X2, X3, ..., XN if fibonacci like if
N > =3
Xi + Xi+1 = Xi+2 for all i+2<=N
 Find the length of the longest Fibonacci-like subsequence of A.
If one does not exist, return 0. Note: A subsequence is derived from another sequence A by deleting any number of elements (including none) from A, without changing the order of the remaining elements.

*/


int Solution::solve(vector<int> &A) {
    
    int n=A.size();
    if(n<=2){ return 0; }
    
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){ mp[A[i]]=i; }
    
    vector<vector<int>> ans(n,vector<int>(n,0));
    
    int mx=0;
    for(int j=1; j<n; j++)
    {
        for(int i=0; i<j; i++)
        {
            if(A[j]-A[i]<A[i] && mp.count(A[j]-A[i]) )
            {  
                int k=mp[A[j]-A[i]];
                ans[i][j]=ans[k][i]+1;
                
                if(ans[i][j]<3){ ans[i][j]=3; }
            }
             mx=max(mx,ans[i][j]);
        }
       
    }
    
    return mx;
}
