/* 
Weight collection
Given a tree T containing N nodes numbered [1,2, …, N] rooted at node 1. 
Each node has a value associated with it. You are also given a number K. You need to find the maximum weight you 
can collect in K-steps. When you traverse an edge, it is counted as 1 step. Weight associated with the traversal 
of an edge connecting node number i and node number j is abs(valueOfNode(i) - valueOfNode(j)). 

Note:
You should start traversing from the root node.
You can traverse an edge from parent to child or from child to parent.
You can traverse an edge multiple times.
*/

void dfs(int i,int A,long long &mx,int lv,long long gn,vector<int> &pr,vector<int> &C,vector<vector<int> > &adj)
{
    int p=1000000007;
    if(pr[i]!=0)
    {
        long long prf= (long long )gn + (long long)(A-(lv-1))*abs(C[i]-C[pr[i]-1]);
        //prf%=p;
        mx=max(mx,prf);
       
        gn= gn+ (long long)abs(C[i]-C[pr[i]-1]); 
        //gn%=p;
    }
    
    if(lv==A){ return; }
    
    for(int j=0; j<adj[i].size(); j++)
    {
        dfs(adj[i][j],A,mx,lv+1,gn,pr,C,adj);
    }
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    
    vector<vector<int> > adj(B.size(),vector<int>({})); 
    
    for(int i=0; i<B.size(); i++)
    {
        if(B[i]!=0)
        {
            adj[B[i]-1].push_back(i);
        }
    }
    
    long long mx=0,gn=0; int lv=0;
    
    dfs(0,A,mx,lv,gn,B,C,adj);
    
    mx%=1000000007;
    
    return (int)mx;
}
