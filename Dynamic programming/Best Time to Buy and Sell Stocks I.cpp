/* 
Best Time to Buy and Sell Stocks I
Say you have an array, A, for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
design an algorithm to find the maximum profit. Return the maximum possible profit.

*/


int Solution::maxProfit(const vector<int> &A) {
    
    if(A.empty()){ return 0; }
    
    int mn=A[0]; int ans=0; 
    
    for(int i=0; i<A.size(); i++)
    {
        ans=max(ans,A[i]-mn);
        mn=min(mn,A[i]);
    }
    return ans;
}
