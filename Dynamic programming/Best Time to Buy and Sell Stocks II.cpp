/* 

Best Time to Buy and Sell Stocks II
Say you have an array, A, for which the ith element is the price of a given stock on day i. Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

int Solution::maxProfit(const vector<int> &A) {
    
    /*int ans[A.size()]; memset(ans,0,sizeof(ans));
    
    int mx=0;
    for(int i=1; i<A.size(); i++)
    {
        ans[i]=ans[i-1];
        for(int j=0; j<i; j++)
        {
            if(A[i]>A[j] && ans[j]+A[i]-A[j]>ans[i])
            {  ans[i]=ans[j]+A[i]-A[j]; }
        }
        mx=max(mx,ans[i]);
    }
    */
    
    if(A.empty()){ return 0; }
    
    int mn=A[0]; int sum=0;
    for(int i=1; i<A.size(); i++)
    {
        if(A[i]<=mn){ mn=A[i]; }
        else
        {
            sum+=A[i]-mn;
            mn=A[i];
        }
    }
    
    return sum;
}
