//Given a string s, find the longest palindromic substring in s. 
//You may assume that the maximum length of s is 1000.

class Solution {
public:
    string longestPalindrome(string A) {
        
        if(A==""){ return A; }
    
        int n=A.size(); int ans[n][n]; memset(ans,0,sizeof(ans));
        int mx=0; int st=0,en=0;

        for(int j=0; j<n; j++)
        {
            for(int i=j; i>=0; i--)
            {
                if(i==j){ ans[i][j]=1; continue; }

                if(A[i]==A[j] && j-i==1){ ans[i][j]=1; }
                else if(A[i]==A[j]){ ans[i][j]=ans[i+1][j-1]; }
                else{ ans[i][j]=0; }

                if(ans[i][j]==1)
                {   
                    if(j-i>en-st){  st=i; en=j; }
                }
            }
        }

        string str="";

        for(int i=st; i<=en; i++){ str+=A[i]; }
        return str;
        
    }
};