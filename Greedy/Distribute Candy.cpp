/* 
Distribute Candy
There are N children standing in a line. Each child is assigned a rating value. 
You are giving candies to these children subjected to the following requirements:
1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give? Input Format:
The first and the only argument contains N integers in an array A.
*/

int Solution::candy(vector<int> &A) {
    
    if(A.empty()){ return 0; }
    
    int ans[A.size()]; memset(ans,0,sizeof(ans));
    ans[0]=1;
    
    for(int i=1; i<A.size(); i++)
    {
        if(A[i]>A[i-1]){ ans[i]=ans[i-1]+1; }
        else{ ans[i]=1; }
    }
    
    int sum=ans[A.size()-1];
    for(int i=A.size()-2; i>=0; i--)
    {
        if(A[i]>A[i+1]){ ans[i]=max(ans[i],ans[i+1]+1); }
        sum+=ans[i];
    }
    
    return sum;
    
}