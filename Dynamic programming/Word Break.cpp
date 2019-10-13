/* 

Word Break
Given a string A and a dictionary of words B, determine if A can be segmented into a space-separated sequence of one or more dictionary words.

*/


int Solution::wordBreak(string A, vector<string> &B) {
    
    int n=A.size();
    
    unordered_map<string,int> mp;
    vector<bool> ans(n,false);
    
    for(int i=0; i<B.size(); i++ )
    {
        mp[B[i]]=1;
    }
    
    for(int j=n-1; j>=0; j--)
    {
        string st="";   ans[j]=0;
        
        for(int i=j; i<n; i++){ st+=A[i]; }
        if(mp.find(st)!=mp.end()){ ans[j]=1; continue; }
        
        st="";
        for(int i=j; i<n-1; i++)
        {
            st+=A[i]; 
            if(mp.find(st)!=mp.end()  && ans[i+1]==1) 
            { ans[j]=1; break; }
        }
    }
    
    return ans[0];
}
