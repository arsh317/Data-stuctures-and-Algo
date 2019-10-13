/* 
Ways to form Max Heap 2
Max heap is a special kind of complete binary tree in which for every node the value 
present in that node is greater than the value present in it’s children nodes. If you want 
to know more about Heaps, please visit this link. So now the problem statement for the question is: 
Given an array of size n consisting of n-1 distinct elements.In other words there is exactly one 
element that is repeated.It is given that the element that would repeat would be either the maximum 
element or the minimum element. Find the number of structurally different max heaps possible using 
all the n elements of the array that is max heap of size n.
 */


int cal(int n,int cond,int ans[][2], vector<vector<int>> &ncr)
{
    if(n<=1){ ans[n][cond]=1; return 1; }
    if(cond==1 && n<=3){ ans[n][cond]=1; return 1; }
    
    if(ans[n][cond]!=-1){ return ans[n][cond]; }
    
    int p=1000000007;
    
    int h=(float)log(n)/log(2);
    int cr_lv=(1<<h);
    int up=cr_lv-1;
    
    int lft=n-up;
    int l,r;
    
    if(lft<=(cr_lv/2) ){ l=lft; }
    else{ l=cr_lv/2; }
    
    r=lft-l;
    l+=(up-1)/2;
    r+=(up-1)/2;
    
    //if(i==7){ cout<<"h :"<<h<<" l: "<<l<<" r: "<<r<<endl; }
    
    if(cond==0)
    {
        long long t=(long long)(ncr[n-1][l])%p*(long long)cal(l,0,ans,ncr)%p*(long long)cal(r,0,ans,ncr)%p;
        ans[n][cond]=(int)(t%p);
        return  ans[n][cond];
    }
    else//cond==1
    {
        long long nr=(long long)(ncr[n-3][l-1])%p*(long long)cal(l,0,ans,ncr)%p*(long long)cal(r,0,ans,ncr)%p;
        long long lsp=(long long)(ncr[n-3][l-2])%p*cal(l,1,ans,ncr)%p*cal(r,0,ans,ncr)%p;
        long long rsp=0;
        if(r>=2){   rsp=(long long)(ncr[n-3][l])%p*cal(l,0,ans,ncr)%p*cal(r,1,ans,ncr)%p;  }
        
        long long t=nr%p + lsp%p + rsp%p;
        
        ans[n][cond]=(int)(t%p);
        return  ans[n][cond];
    }
    //cout<<i-1<<","<<l<<" : "<<ncr[i-1][l]<<endl;
}



int Solution::solve(vector<int> &B) {
    
    int A=B.size();
    
    vector< vector<int> > ncr;
    vector<int> vt;
    for(int i=0; i<=A; i++){ vt.push_back(0); }
    
    ncr.assign(A+1,vt);
    
    int p=1000000007;
    
    int ans[A+1][2];
    
    int mx=INT_MIN,mn=INT_MAX,rep;
    for(int i=0; i<=A; i++)
    {
        if(i<A){  mx=max(mx,B[i]);  mn=min(mn,B[i]);  }
        
        for(int j=0; j<=A; j++)
        {
            if(i<A && j<i){ if(B[j]==B[i]){ rep=B[i]; } }
            
            if(i==j){ ncr[i][j]=1; continue; }
            else if(j==0){ ncr[i][j]=1; continue; }
            else if(j>i){ ncr[i][j]=-1; continue; }
            
            long long t= ( (long long)(ncr[i-1][j-1])%p +(long long)(ncr[i-1][j])%p )%p;
            ncr[i][j]=(int)(t%p);
        }
    }
    
    int cond=0;
    if(rep==mn){ cond=1; }
    
    for(int i=0; i<=A; i++)
    {
        ans[i][0]=-1; ans[i][1]=-1;
    }
    
    return cal(A,cond,ans,ncr);

}
