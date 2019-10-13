/* 

Let's Party
In Danceland, one person can party either alone or can pair up with another person. Can you find in how many ways they can party if there are N people in Danceland?

*/


int Solution::solve(int A) {
    
    int ans[A+1]; memset(ans,0,sizeof(ans));
    ans[0]=1; ans[1]=1;
    int mod=10003;
    
    for(int i=2; i<=A; i++)
    {
        ans[i]=ans[i-1]%mod +(i-1)%mod*ans[i-2]%mod;
        ans[i]%=mod;
    }
    
    return ans[A];
}
