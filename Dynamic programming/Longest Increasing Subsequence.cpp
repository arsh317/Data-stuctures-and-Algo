/* 
Longest Increasing Subsequence
Find the longest increasing subsequence of a given array of integers, A. In other words, find a subsequence of array in which the subsequence's elements are in strictly increasing order, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique. In this case, we only care about the length of the longest increasing subsequence.
*/

int Solution::lis(const vector<int> &A) {
    
    if(A.empty()){ return 0; }
    
    int ins[A.size()],dcs[A.size()];
    memset(ins,0,sizeof(ins));
    
    ins[0]=1; 
    
    int mx=1;
   
    for(int i=1; i<A.size(); i++)
    {
        ins[i]=1;
        for(int j=0; j<i; j++)
        {
            if(A[i]>A[j] && ins[j]+1>ins[i])
            { ins[i]=ins[j]+1; } 
        }
        mx=max(mx,ins[i]);
    }
    
    return mx;
}
