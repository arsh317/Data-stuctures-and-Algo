/**
Move all zeroes to end of the array . Given an array of integers A, push all the zeroes in 
the array to the end of the array keeping the order of all the remaining elements same.
More formally, if A[i] and A[j] are two non zero elements and A[i] is in the left A[j] in the
original array then A[i] will be in the left of A[j] in the final answer as well.
 */
vector<int> Solution::solve(vector<int> &A) {
    
    int dn=0;
    
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]!=0)
        {
            int tmp=A[i];
            A[i]=A[dn];
            A[dn]=tmp;
            dn++;
        }
    }
    
    return A;
}
