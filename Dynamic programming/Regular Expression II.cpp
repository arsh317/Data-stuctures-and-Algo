/* 

Regular Expression II
Implement regular expression matching with support for '.' and '*'. '.' Matches any single character. '*' Matches zero or more of the preceding element. The matching should cover the entire input string (not partial). 

*/

int Solution::isMatch(const string A, const string B) {
    
    if(B=="" && A==""){ return 1; }
    if(B==""){ return 0; }
    
    string str="";
    int n=A.size(),m=B.size();
    
    int i=0;
    while(i<m)
    {
        if(i+1<m && B[i+1]=='*')
        {
            if(B[i]=='.'){  str+='#'; }
            else{ str+=(char)(B[i]-32);  }
            i++;
            while(i<m && B[i]=='*'){ i++; }
        }
        else
        { str+=B[i]; i++; }
    }
    
    //cout<<str<<endl;
    m=str.size();
    
    vector<vector<bool>> ans(n+1,vector<bool>(m+1,false));
    ///int ans[n+1][m+1]; memset(ans,0,sizeof(ans));
    
    for(i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i==0 && j==0){ ans[i][j]=1; continue; } //when both the string and pattern are empty(Its a match)
            
            if(i==0)//When string is empty. All the remaining pattern chars should be '*' for  a match
            { ans[i][j]=( (str[j-1]>=65 && str[j-1]<=90) || (str[j-1]=='#') )&&(ans[i][j-1]);  continue; }
            
            if(j==0){ ans[i][j]=0; continue; }// when pattern is empty but string is not(Mismatch)
            
            if(str[j-1]>=97 && str[j-1]<=122)//when pattern char is lowercase
            {  ans[i][j]= (A[i-1]==str[j-1])&&(ans[i-1][j-1]);  }
            
            else if(str[j-1]>=65 && str[j-1]<=90) // uppercase letter
            {
                if(A[i-1]-str[j-1]==32)
                {  ans[i][j]=ans[i-1][j] || ans[i][j-1];   }
                else  //diff letters
                {  ans[i][j]=ans[i][j-1];   }
            }
            
            else if(str[j-1]=='#') // curr pattern char is '.*'
            {   ans[i][j]=ans[i-1][j] || ans[i][j-1];   }
            
            else // // curr pattern char is single '.'
            {   ans[i][j]=ans[i-1][j-1];    }
            
        }
    }
   
    return ans[n][m];

}
