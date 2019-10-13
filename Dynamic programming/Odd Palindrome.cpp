/* 

Odd Palindrome
A palindrome string is a string which reads the same forward and backward. If a palindrome string is of odd length l, then (l+1)/2th character (1 index based) is said to be the centre of the palindrome. You are given a string A. Return an array X of integers where X[i] = (number of odd length palindrome subsequence of A with A[i] as the centre) modulo 1000000007. A subsequence of A is a string which can be derived from A by deleting some of its character.

*/
vector<int> Solution::solve(string A) {
    
    vector<int> vt; 
    if(A.empty()){ return vt; }
    if(A.size()==1){ return {1}; }
    
    int n=A.size();
    vector<vector<int>> ans(n,vector<int>(n,0));
    int p=1000000007;
    
    for(int j=n-1; j>=0; j--)
    {
        for(int i=0; i<j; i++)
        {
            if(i==0 && j==n-1)
            {
                ans[i][j]= (A[i]==A[j]);
            }
            
            /*long long tmp=0;
            if(A[i]!=A[j])
            {
                if(i-1>=0){  tmp+=(long long)ans[i-1][j]%p; tmp%=p;  }
                if(j+1<=n-1){ tmp+=(long long)ans[i][j+1]%p; tmp%=p; }
                if(i-1>=0 && j+1<=n-1){ tmp-=(long long)ans[i-1][j+1]%p; tmp%=p;   }
                if(tmp<0){ tmp+=p; }
                tmp%=p;
                ans[i][j]=(int)tmp; 
            }
            else
            {
                if(i-1>=0){  tmp+=(long long)ans[i-1][j]%p; tmp%=p;  }
                if(j+1<=n-1){ tmp+=(long long)ans[i][j+1]%p; tmp%=p; }
                tmp+=1; tmp%=p;  
                ans[i][j]=(int)tmp; 
            }
            */
        
            ans[i][j]=0;  long long tmp=0;
            if(i-1>=0){  tmp+=(long long)ans[i-1][j]%p; tmp%=p;  }
            if(j+1<=n-1){ tmp+=(long long)ans[i][j+1]%p; tmp%=p; }
            if(i-1>=0 && j+1<=n-1){ tmp-=(long long)ans[i-1][j+1]%p; tmp%=p;   }
            if(tmp<0){ tmp+=p; }
            if(A[i]==A[j])
            {
                tmp+=(long long)1; tmp%=p;  
                if(i-1>=0 && j+1<=n-1){  tmp+=(long long)ans[i-1][j+1]%p;  tmp%=p;  }
            }
            tmp%=p;
            ans[i][j]=(int)tmp;
            
        }
    }
    
    vt.push_back(1);
    for(int i=1; i<n-1; i++)
    {
        vt.push_back(ans[i-1][i+1]+1);
    }
    vt.push_back(1);
    
    return vt;
}
