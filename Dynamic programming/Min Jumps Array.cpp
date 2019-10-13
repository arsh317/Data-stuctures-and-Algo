/* 
Min Jumps Array
Given an array of non-negative integers, A, of length N, you are initially positioned at the first index of the array. Each element in the array represents your maximum jump length at that position. Return the minimum number of jumps required to reach the last index. If it is not possible to reach the last index, return -1.
*/
int Solution::jump(vector<int> &A) {
    
    /*
    DP solution

    int arr[A.size()];
    memset(arr,-1,sizeof(arr));
    
    arr[0]=0;
    for(int i=1; i<A.size(); i++)
    {
        //arr[i]=INT_MAX;
        for(int j=0; j<i; j++)
        {
            if(arr[j]!=-1 && arr[i]==-1 && j+A[j]>=i){ arr[i]=arr[j]+1; }
            else if(j+A[j]>=i && arr[j]+1<arr[i]){ arr[i]=arr[j]+1; }
        }
        //if(arr[i]==INT_MAX){ arr[i]=-1; }
    }
    return arr[A.size()-1];
    */
    
    if(A.size()<=1){ return 0; }
    
    int maxr=A[0],i=0,nxtpt=maxr;
    
    int jump=0;
    while(i<A.size())
    {
        if(maxr>=A.size()-1){ return jump+1; }
        while(i<=maxr)
        { nxtpt=max(nxtpt,i+A[i]); i++; continue; }
        
        if(nxtpt<=maxr){ return -1; }
        maxr=nxtpt; jump++;
    }
    //if(mxr>=A.size()-1){ return ct; }
    return -1;
}
