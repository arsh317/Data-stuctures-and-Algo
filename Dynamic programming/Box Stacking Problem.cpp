/* 

Box Stacking Problem
Given a matrix of integers A of size N x 3 representing the dimensions of N rectangular 3-D boxes, where A[i][0] represents the height of the ith box, A[i][1] represents the widht of the ith box and A[i][2] represents the length of the ith box. You want to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. You can rotate a box so that any side functions as its base. It is also allowable to use multiple instances of the same type of box.

*/



struct box
{
    int bs1,bs2;
    int ht;
    
    box(int b1,int b2,int h)
    {
        bs1=b1; bs2=b2;
        ht=h;
    }
    
};


bool comp(box a,box b)
{
    long long ar1=(long long)a.bs1*(long long)a.bs2;
    long long ar2=(long long)b.bs1*(long long)b.bs2;
    return  ar1 < ar2;
}

int Solution::solve(vector<vector<int> > &A) {
    
    if(A.empty()){ return 0; }
    
    vector<box> vt;
    
    for(int i=0; i<A.size(); i++)
    {
        vt.push_back( box(A[i][0],A[i][1],A[i][2]) );
        vt.push_back( box(A[i][1],A[i][2],A[i][0]) );
        vt.push_back( box(A[i][0],A[i][2],A[i][1]) );
    }
    
    sort(vt.begin(),vt.end(),comp);
    
    vector<int> ans(vt.size(),0);
    
    int mx=0; ans[0]=vt[0].ht;
    for(int i=1; i<vt.size(); i++)
    {
        ans[i]=vt[i].ht;
        for(int j=0; j<i; j++)
        {
            if( (vt[i].bs1>vt[j].bs1 && vt[i].bs2>vt[j].bs2) || (vt[i].bs1>vt[j].bs2 && vt[i].bs2>vt[j].bs1))
            {   ans[i]=max(ans[i],ans[j]+vt[i].ht); }
        }
        mx=max(mx,ans[i]);
    }
    
    return mx;
}
