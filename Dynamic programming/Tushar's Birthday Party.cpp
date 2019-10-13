/* 

Tushar's Birthday Party
As it is Tushar's Birthday on March 1st, he decided to throw a party to all his friends at TGI Fridays in Pune. Given are the eating capacity of each friend, filling capacity of each dish and cost of each dish. A friend is satisfied if the sum of the filling capacity of dishes he ate is equal to his capacity. Find the minimum cost such that all of Tushar's friends are satisfied (reached their eating capacity). NOTE:
Each dish is supposed to be eaten by only one person. Sharing is not allowed.
Each friend can take any dish unlimited number of times.
There always exists a dish with filling capacity 1 so that a solution always exists.

*/

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    
    int mx=INT_MIN;  int n=B.size();
    for(int i=0; i<A.size(); i++)
    {  mx=max(mx,A[i]);   }
    
    //cout<<mx<<endl;
    
    vector<vector<long long>> ans(mx+1,vector<long long>(n,INT_MAX));
    
    for(int i=0; i<=mx; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0){ ans[i][j]=0; continue; }
            if(j==0)
            {
                if(B[j]<=i){ ans[i][j]=ans[i-B[j]][j]+C[j]; }
                else{ ans[i][j]=INT_MAX; }
                continue;
            }
            if(B[j]>i){ ans[i][j]=ans[i][j-1]; }
            else{ ans[i][j]=min(ans[i][j-1],ans[i-B[j]][j]+C[j]); }
        }
    }
    
    int sum=0;
    for(int i=0; i<A.size(); i++)
    {
        //cout<<i<<" : "<<ans[3][i]<<endl;
        //cout<<A[i]<<": "<<ans[A[i]][n-1]<<endl;
        sum+=(int)ans[A[i]][n-1];
    }
    
    return  sum;
}