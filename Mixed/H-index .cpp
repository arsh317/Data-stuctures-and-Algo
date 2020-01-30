H-index
Given an array of citations A (each citation is a non-negative integer) of a researcher, write a function to compute the researchers h-index. According to the definition of h-index: A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each.


int Solution::solve(vector<int> &A) {
    
    if(A.empty()){ return 0; }
    
    sort(A.begin(),A.end());
    
    int ans=0;
    if(A[0]>=(A.size()) ){ return A.size(); }
    
    for(int i=A.size()-1; i>=0; i--)
    {
        int ct=A.size()-i;
        
        if(A[i]>=ct && ( (i-1)>=0 && A[i-1]<=ct ) )
        { ans=max(ans,ct); }
    }
    
    return ans;
}
