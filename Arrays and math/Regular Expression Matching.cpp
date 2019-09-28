//Given an input string (s) and a pattern (p),
//implement regular expression matching with support for '.' and '*'.

//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.


class Solution {
public:
    bool isMatch(string s, string p) {
        
        
        int s1=s.size(); int s2=p.size();
        if(s1==0 && s2==0){ return 1; }
        if(s2==0){ return 0; }
        vector<vector<bool>> dp(s1+1,vector<bool>(s2+1,0));
        
        for(int i=0; i<=s1; i++)
        {
            for(int j=0; j<=s2; j++)
            {
                
                if(i==0 && j==0){ dp[i][j]=1;  continue; }
                if(j==0){ dp[i][j]=0;  continue; }                
                
                if(i==0)
                {
                    if(p[j-1]!='.' && p[j-1]!='*'){ dp[i][j]=0; continue; }
                    if(p[j-1]=='.'){ dp[i][j]=0; continue; } 
                    if(p[j-1]=='*')
                    {
                        if(j==1){ dp[i][j]=0; continue; }
                        dp[i][j]=dp[i][j-2];   
                        continue;
                    }
                }
                
                if(j==1)
                { dp[i][j]=((s[i-1]==p[j-1] || p[j-1]=='.')  && dp[i-1][j-1] ); continue; }
                
                //dp[i][j]=0; continue; 
                
                
                if(s[i-1]==p[j-1]){ dp[i][j]=dp[i-1][j-1]; }
                else if(p[j-1]=='.'){ dp[i][j]=dp[i-1][j-1]; }
                else if( p[j-1]=='*' && (p[j-2]==s[i-1] || p[j-2]=='.') )
                { dp[i][j]=dp[i-1][j] || dp[i][j-2]; }
                else if( p[j-1]=='*'){ dp[i][j]= dp[i][j-2]; }
                else{ dp[i][j]=0; }
                
            }
        }
        
   
        
        
        return dp[s1][s2];
        
    }
};