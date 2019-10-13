/* 
Minimum Number of Squares
Given an integer N. Return count of minimum numbers, sum of whose squares is equal to N. Example: N=6 Possible combinations are :
(12 + 12 + 12 + 12 + 12 + 12)
(12 + 12 + 22)
So, minimum count of numbers is 3 (i.e. 1,1,2). Note: 1 ≤ N ≤ 10
*/

int Solution::countMinSquares(int A) {
    
    int ans[A+1]; memset(ans,0,sizeof(ans));
    ans[1]=1;
    
    for(int i=2; i<=A; i++)
    {
        int n=sqrt(i); int mn=INT_MAX;
        for(int j=1; j<=n; j++)
        {
            mn=min(mn,ans[i-j*j]);
        }
        if(mn==INT_MAX){ ans[i]=mn; }
        else{ ans[i]=mn+1; }
    }
    
    return ans[A];
}
