/*
You are given an array of N integers, A1, A2 ,..., AN. Return maximum value of f(i, j) 
for all 1 ≤ i, j ≤ N. f(i, j) is defined as |A[i] - A[j]| + |i - j|, 
where |x| denotes absolute value of x.
*/
int Solution::maxArr(vector<int> &A) {
    
    if(A.size()<=1){ return 0; }
    
    int arr1[A.size()],arr2[A.size()];
    
    for(int i=0; i<A.size(); i++)
    {
        arr1[i]=A[i]+i;
        arr2[i]=A[i]-i;
    }
    
    int max1=arr1[0],min1=arr1[0],max2=arr2[0],min2=arr2[0];
    
    for(int i=0; i<A.size(); i++)
    {
        if(arr1[i]>max1){ max1=arr1[i]; }
        if(arr1[i]<min1){ min1=arr1[i]; }
        
        if(arr2[i]>max2){ max2=arr2[i]; }
        if(arr2[i]<min2){ min2=arr2[i]; }
    }
    
    return max(max1-min1,max2-min2);
    
    
}
