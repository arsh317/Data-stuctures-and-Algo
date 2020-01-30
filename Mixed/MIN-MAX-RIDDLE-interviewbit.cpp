MIN MAX RIDDLE
Given an array of integers A of size N. Find and return an array containing the maximum of the minimum(s) of every window size in the array. The window size varies from 1 to N.

vector<int> Solution::solve(vector<int> &A) {
    
    stack<int> st;
    
    int n=A.size();
    //int nle[n],ple[n]; memset(nle,n,sizeof(nle)); memset(ple,-1,sizeof(ple));
    
    vector<int> nle(n,n),ple(n,-1);
    
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && A[i]<A[st.top()])
        {
            nle[st.top()]=i; st.pop();
        }
        st.push(i);
    }
    
    while(!st.empty()){ st.pop(); }
    
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && A[i]<A[st.top()])
        {
            ple[st.top()]=i; st.pop();
        }
        st.push(i);
    }
    
    vector<int> ans(n+1,0);
    
    
    for(int i=0; i<n; i++)
    {
        int ln=nle[i]-ple[i]-1;
        //cout<<ln<<endl;
        ans[ln]=max(ans[ln],A[i]);
    }
    
    for(int i=n-1; i>=1; i--)
    {
        ans[i]=max(ans[i],ans[i+1]);
    }
    
    
    ans.erase(ans.begin());
    return ans;
    
    
}
