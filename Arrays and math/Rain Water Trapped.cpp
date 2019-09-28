/**
Rain Water Trapped
Given n non-negative integers representing an elevation map where 
the width of each bar is 1, compute how much water it is able to trap after raining.
 */
int Solution::trap(const vector<int> &A) {
    
    int l=A.size();
    while(l>0 && A[l-1]==0){ l--; }
    
    if(l<1){ return 0; }
    
    int i=0;
    while(i<l && A[i]==0){ i++; }
    
    int mx=i; int ans=0;
    for(i=i+1; i<l; i++)
    {
        if(A[i]>=A[mx]){ mx=i; }
        else{ ans=ans+A[mx]-A[i]; }
    }
    
    if(A[l-1]>=A[mx]){ return ans; }
    
    int rmx=l-1;
    for(i=l-1; i>mx; i--)
    { 
        if(A[i]>=A[rmx]){ rmx=i; }
        ans=ans-(A[mx]-A[rmx]);
    }
    
    return ans;
}
