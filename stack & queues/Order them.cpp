/*
Order them
Given an array of integers A describing ranking of trucks. Your task is to insert these rank in another array B by some means of operations such that B is sorted in ascending order. For performing these operations you can use one stack C. In one Operation you can perform any of the following steps:
Remove the first element from A and append at the back of C.
Remove the last element from C and append at the back of B.
Remove the first element from A and append at the back of B.
you can perform these operations any number of times (possibly zero). Return 1 if B can be formed in ascending order using some operations else return 0.
*/

int Solution::solve(vector<int> &A) {
    
    int need=1;
    int arr[A.size()]; int top=-1;
    for(int i=0; i<A.size(); i++){ arr[i]=0; }
    
    
    for(int i=0; i<A.size(); i++)
    {
        while(top>=0 && arr[top]==need )
        {
            need++; top--;
        }
        if(A[i]==need){ need++; }
        else{ top++; arr[top]=A[i]; }
    }
    while(top>=0 && arr[top]==need )
    {
        need++; top--;
    }
    
    if(top>=0){ return 0; }
    return 1;
    
}
