/*
Maximum Unsorted Subarray
You are given an array (zero indexed) of N non-negative integers, A0, A1 ,..., AN-1.
Find the minimum sub array Al, Al+1 ,..., Ar so if we sort(in ascending order)
that sub array, then the whole array should get sorted. If A is already sorted, output -1
*/

vector<int> Solution::subUnsort(vector<int> &A) {
    
    vector<int> vt;
    if(A.size()<=1){ vt.push_back(-1); return vt; }
    
    int i=1;
    while(i<A.size() && A[i]>=A[i-1]){ i++; }
    if(i==A.size()){ vt.push_back(-1); return vt; }
    
    int j=A.size()-2;
    while(j>=0 && A[j]<=A[j+1]){ j--; }
    i--; j++;
    
    int mn=A[i],mx=A[i];
    for(int k=i; k<=j; k++)
    {
        if(A[k]>mx){mx=A[k]; }
        if(A[k]<mn){mn=A[k]; }
    }
    
    while(i-1>=0 && A[i-1]==mx){ i--; }
    while(j+1<A.size() && A[j+1]==mn){ j++; }
    if(i<0 || j>=A.size()){ vt.push_back(-1); return vt; }
    //cout<<i<<" "<<j<<endl;
    for(int k=0; k<i; k++)
    {
        if(A[k]>mn){ i=k; break; }
    }
    
    for(int k=A.size()-1; k>=j+1; k--)
    {
        if(A[k]<mx ){ j=k; break; }
    }
    
    vt.push_back(i);
    vt.push_back(j);
   
    
    return vt;
}
