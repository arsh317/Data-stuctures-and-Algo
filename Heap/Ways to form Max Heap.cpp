/* 
Ways to form Max Heap
Max Heap is a special kind of complete binary tree in which for every node the value present in that 
node is greater than the value present in it’s children nodes. If you want to know more about Heaps, 
please visit this link So now the problem statement for this question is: How many distinct Max Heap 
can be made from n distinct integers In short, you have to ensure the following properties for the max heap :
Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, 
except possibly the last, is completely filled, and all nodes are as far left as possible. )
Every node is greater than all its children
 */



int Solution::solve(int A) {
    
    int ncr[A+1][A+1];
    int p=1000000007;
    
    int ans[A+1];
    
    for(int i=0; i<=A; i++)
    {
        for(int j=0; j<=A; j++)
        {
            if(i==j){ ncr[i][j]=1; continue; }
            else if(j==0){ ncr[i][j]=1; continue; }
            else if(j>i){ ncr[i][j]=-1; continue; }
            
            long long t= ( (long long)(ncr[i-1][j-1])%p +(long long)(ncr[i-1][j])%p )%p;
            ncr[i][j]=(int)(t%p);
            //if(i>10 && j>10){ cout<<i<<","<<j<<" : "<<ncr[i][j]<<endl; }
        }
    }
    
    for(int i=0; i<=A; i++)
    {
        if(i<=1){ ans[i]=1; continue; }
        
        int h=(float)log(i)/log(2);
        int cr_lv=(1<<h);
        int up=cr_lv-1;
        
        int lft=i-up;
        int l,r;
        
        if(lft<=(cr_lv/2) ){ l=lft; }
        else{ l=cr_lv/2; }
        
        r=lft-l;
        l+=(up-1)/2;
        r+=(up-1)/2;
        
        //if(i==7){ cout<<"h :"<<h<<" l: "<<l<<" r: "<<r<<endl; }
        
        long long t=(long long)(ncr[i-1][l])%p*(long long)(ans[l])%p*(long long)(ans[r])%p;
        ans[i]=(int)(t%p);
        //cout<<i-1<<","<<l<<" : "<<ncr[i-1][l]<<endl;
    }
    
    //for(int i=0; i<=A; i++){ cout<<i<<" : "<<ans[i]<<endl; }
    
    return ans[A];
}
