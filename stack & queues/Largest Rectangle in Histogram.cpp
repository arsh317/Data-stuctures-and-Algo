/*
Largest Rectangle in Histogram
Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.
Find the area of largest rectangle in the histogram.
*/
 
void calcnle(vector<int> &A,int nle[])
{
    stack<int> st;

    for(int i=0; i<A.size(); i++)
    {
        if(st.empty()){ st.push(i); }
        else if(!st.empty() && A[st.top()]<=A[i]){ st.push(i); }
        else
        {
            while(!st.empty() && A[st.top()]>A[i])
            { nle[st.top()]=i; st.pop();  }
            st.push(i);
        }
    }
    
    while(!st.empty())
    {  nle[st.top()]=A.size(); st.pop();  }
    
}

void calcple(vector<int> &A,int ple[])
{
    stack<int> st;
   
    for(int i=A.size()-1; i>=0; i--)
    {
        if(st.empty()){ st.push(i); }
        if(!st.empty() && A[st.top()]<=A[i]){ st.push(i); }
        else
        {
            while(!st.empty() && A[st.top()]>A[i])
            { ple[st.top()]=i; st.pop();  }
            st.push(i);
        }
    }
    
    while(!st.empty() )
    {  ple[st.top()]=-1; st.pop();  }
}



int Solution::solve(vector<vector<int> > &A) {
    
    vector<vector<int> > ones;
    int n=A.size(),m=A[0].size();
    for(int i=0; i<n; i++)
    {
        vector<int> vt;
        for(int j=0; j<m; j++)
        { vt.push_back(0); }
        ones.push_back(vt);
    }
    
    for(int j=0; j<m; j++)
    {
        int sum=0; 
        for(int i=0; i<n; i++)
        {
            if(A[i][j]==1){ sum++; }
            else{ sum=0; }
            
            ones[i][j]=sum;
           // cout<<ones[i][j]<<" ";
        }
        //cout<<endl;
    }
    
    int mx=0;
    for(int i=0; i<n; i++)
    {
        int nle[m],ple[m];
        memset(nle,0,sizeof(nle));
        memset(ple,0,sizeof(ple));
        calcnle(ones[i],nle);
        calcple(ones[i],ple);
        
        for(int j=0; j<m; j++)
        {
            //cout<<nle[j]<<"#"<<ple[j]<<" ";
            int x=(nle[j]-ple[j]-1)*ones[i][j];
            mx=max(mx,x);
        }
        //cout<<endl;
    }
    
    return mx;
    
}
int Solution::largestRectangleArea(vector<int> &A) {
    
    stack<int> st;
    int nle[A.size()],ple[A.size()];
    memset(nle,-1,sizeof(nle));
    memset(ple,-1,sizeof(ple));
    
    for(int i=0; i<A.size(); i++)
    {
        if(st.empty()){ st.push(i); }
        else if(!st.empty() && A[st.top()]<=A[i]){ st.push(i); }
        else
        {
            while(!st.empty() && A[st.top()]>A[i])
            { nle[st.top()]=i; st.pop();  }
            st.push(i);
        }
    }
    
    
    while(!st.empty())
    {  nle[st.top()]=A.size(); st.pop();  }
    
    for(int i=A.size()-1; i>=0; i--)
    {
        if(st.empty()){ st.push(i); }
        if(!st.empty() && A[st.top()]<=A[i]){ st.push(i); }
        else
        {
            while(!st.empty() && A[st.top()]>A[i])
            { ple[st.top()]=i; st.pop();  }
            st.push(i);
        }
    }
    
    while(!st.empty() )
    {  ple[st.top()]=-1; st.pop();  }
    
    int mx=0;
    for(int i=0; i<A.size(); i++)
    {
        //cout<<nle[i]<<" "<<ple<<endl;
        int x=A[i]*(nle[i]-ple[i]-1);
        mx=max(mx,x);
    }
    
    return mx;
    
}
