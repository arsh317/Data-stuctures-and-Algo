/*
Max Chunks To Make Sorted
Given an array of integers A of size N that is a permutation of [0, 1, 2, ..., (N-1)],
if we split the array into some number of "chunks" (partitions), and individually sort each 
chunk.After concatenating them, the result equals the sorted array.
*/
int Solution::solve(vector<int> &A) {
    
    if(A.size()==0){ return 0; }
    if(A.size()==1){ return 1; }
    
    int mx=A[0],ans=0;
    
    for(int i=0; i<A.size(); i++)
    {  
        if(A[i]>mx){ mx=A[i]; }
        if(mx<=i){ ans++; }
    }
    
    return ans;
}
