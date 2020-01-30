Remove the Substring
Given 2 strings of lowercase alphabets A and B of size N and M respectively. it is guaranteed that B is a subsequence of A.


int Solution::solve(string A, string B) {
    
    int n=B.size();
    
    vector<int> l(n,0),r(n,0);
    
    int j=0;
    
    for(int i=0; i<A.size() && j<n; i++)
    {
        if(A[i]==B[j]){ l[j]=i; j++; }
    }
    
    j=n-1;
    
    for(int i=A.size()-1 ; i>=0 && j>=0; i--)
    {
        if(A[i]==B[j]){ r[j]=i; j--; }
    }
    
    int ans=r[0];
    for(int i=0; i<n; i++)
    {
        int lf=l[i],rt=A.size();
        if(i+1<n){ rt=r[i+1]; }
        
        ans=max(ans,rt-lf-1);
    }
    
    return ans;
}
