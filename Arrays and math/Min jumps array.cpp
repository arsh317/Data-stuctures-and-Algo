int Solution::jump(vector<int> &A) {
    
    /* Dp sol
    if(A.size()==1){ return 0; }
    int arr[A.size()];
    
    for(int i=0; i<A.size(); i++){ arr[i]=0; }
    
    for(int i=1; i<A.size(); i++)
    {
        int min=INT_MAX;
        for(int j=0; j<i; j++)
        {
            if(A[j]>=i-j && arr[j]!=INT_MAX && arr[j]+1<min)
            { min=arr[j]+1; }
        }
        arr[i]=min;
    }xc
    
    if(arr[A.size()-1]==INT_MAX){ return -1; }
    return arr[A.size()-1];
    */
    
    //Greedy O(n) sol
    if(A.size()<=1){ return 0; }
    
    int step=A[0],maxrch=A[0],jump=0;
    for(int i=1; i<A.size(); i++)
    {
        if(step==0){ return -1; }
        maxrch=max(i+A[i],maxrch);
        step--;
        
        if(step==0)
        {
            jump++; step=maxrch-i; 
            if(maxrch >= A.size()-1){ return (jump+1); } 
        }
    }
    if(maxrch >= A.size()-1){ return (jump+1); }
    return -1;
    
}
