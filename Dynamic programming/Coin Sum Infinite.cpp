/* 

Coin Sum Infinite
You are given a set of coins S. In how many ways can you make sum N assuming you have infinite amount of each coin in the set. Note : Coins in set S will be unique. Expected space complexity of this problem is O(N).

*/

int count( vector<int> &S,int n)
{
    
    int m=S.size();
    int table[n+1];
 
   
    memset(table, 0, sizeof(table));
 
    table[0] = 1;
 
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            { table[j] += table[j-S[i]]; table[j]=table[j]%1000007; }
 
    return table[n];
}

int Solution::coinchange2(vector<int> &A, int B) {
    
    return count(A,B);
}