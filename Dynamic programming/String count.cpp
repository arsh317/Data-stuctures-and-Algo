/* 

String count
Given an integer A, Find and return (total number of binary strings of length A, without having consecutive 1's) % 10^9 + 7.

*/

int Solution::solve(int A) {
    
    //int ans[A+1]; memset(ans,0,sizeof(ans));
    long long int ans=1,mod=1000000007;
    long long int one=1,zr=1;
    
    for(int i=2; i<=A; i++)
    {
        ans=2%mod*zr%mod+one%mod;
        ans%=mod;
        long long int t=one%mod;
        one=zr%mod;  one%=mod;
        zr=t+zr%mod; zr%=mod;
    }
    
    return (int)ans;
}
