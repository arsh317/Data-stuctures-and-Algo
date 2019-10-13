/* 
Max Product Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest product. Return an integer corresponding to the maximum product possible.
*/

int Solution::maxProduct(const vector<int> &A) {
    
    if(A.empty()){ return 0; }
    
    int maxm[A.size()],minm[A.size()];
    memset(maxm,0,sizeof(maxm));
    memset(minm,0,sizeof(minm));
    
    maxm[0]=minm[0]=A[0];
    int mx=A[0];
    
    for(int i=1; i<A.size(); i++)
    {
        if(A[i]>=0)
        {
            maxm[i]=max(A[i],maxm[i-1]*A[i]);
            minm[i]=min(A[i],minm[i-1]*A[i]);
        }
        else
        {
            maxm[i]=max(A[i],minm[i-1]*A[i]);
            minm[i]=min(A[i],maxm[i-1]*A[i]);
        }
        
        mx=max(mx,maxm[i]);
    }
    
    return mx;
}
