/*
Min Steps in Infinite Grid
You are in an infinite 2D grid where you can move in any of the 8 directions :
*/
int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    if(A.size()<=1){ return 0; }
    int ans=0;
    for(int i=1; i<A.size(); i++)
    {
        ans=ans+max(abs(A[i]-A[i-1]),abs(B[i]-B[i-1]));
    }
    return ans;
    
}
