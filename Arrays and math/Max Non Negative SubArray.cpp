/*
Given an array of integers, A of length N, 
find out the maximum sum sub-array of non negative numbers from A. 
The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth 
element and skipping the third element is invalid. Maximum sub-array is defined in terms of the
sum of the elements in the sub-array. Find and return the required subarray.
*/
vector<int> Solution::maxset(vector<int> &A) {
    
    vector<int> vt;
    long long int st=0,en=0,ans=0;
    int fl=0;
    
    int i=0;
    while(i<A.size())
    {
        long long int sum=0,ct=0;
        while(i<A.size() && A[i]>=0)
        {
            fl=1;
            sum+=A[i];
            ct++;
            i++;
        }
        
        if(sum>ans){ ans=sum; st=i-ct; en=i-1;  }
        else if(sum==ans && ct>en-st+1){ ans=sum; st=i-ct; en=i-1; }
        
        while(i<A.size() && A[i]<0){ i++; }
        
    }
    if(fl==0){ return vt; }
    
    for(i=st; i<=en; i++)
    { vt.push_back(A[i]); }
    
    return vt;
}
