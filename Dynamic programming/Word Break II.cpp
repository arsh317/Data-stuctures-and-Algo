/* 

Word Break II
Given a string A and a dictionary of words B, add spaces in A to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

*/


vector<string> Solution::wordBreak(string A, vector<string> &B) {
    
    int n=A.size();
    
    unordered_map<string,int> mp;
    vector< vector<string> > ans(n,vector<string>({}));
    
    for(int i=0; i<B.size(); i++ )
    {
        mp[B[i]]=1;
    }
    
    for(int j=n-1; j>=0; j--)
    {
        string st="";   //ans[j]={};

        for(int i=j; i<n-1; i++)
        {
            st+=A[i]; 
            if(mp.find(st)!=mp.end() ) 
            { 
                for(int k=0; k<ans[i+1].size(); k++)
                {
                    string temp=st+" "+ans[i+1][k];
                    ans[j].push_back(temp);
                }
            }
        }
        
        st+=A[n-1];
        if(mp.find(st)!=mp.end()){ ans[j].push_back(st);  }
    }
    
    return ans[0];
}
