/* 
Length of Longest Subsequence
Given an array of integers, A of length N, find the length of longest subsequence which is first increasing then decreasing.
 */

int Solution::longestSubsequenceLength(const vector<int> &A) {
    
    if(A.empty()){ return 0; }
    
    int ins[A.size()],dcs[A.size()];
    memset(ins,0,sizeof(ins));
    memset(dcs,0,sizeof(dcs));
    
    ins[0]=1; dcs[A.size()-1]=1;
   
    for(int i=1; i<A.size(); i++)
    {
        ins[i]=1;
        for(int j=0; j<i; j++)
        {
            if(A[i]>A[j] && ins[j]+1>ins[i])
            { ins[i]=ins[j]+1; } 
        }
    }
    
    for(int i=A.size()-2; i>=0; i--)
    {
        dcs[i]=1;
        for(int j=i+1; j<A.size(); j++)
        {
            if(A[i]>A[j] && dcs[j]+1>dcs[i])
            { dcs[i]=dcs[j]+1; } 
        }
    }
    
    int mx=0;
    for(int i=0; i<A.size(); i++)
    {
        //cout<<ins[i]<<" : "<<dcs[i]<<endl;
        mx=max(mx,(ins[i]+dcs[i]-1));
    }
    
    return mx;
    
}
