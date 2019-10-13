/* 

Distinct Subsequences
Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B. Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

*/
int Solution::numDistinct(string A, string B) {
    
    int n=A.size(),m=B.size();
    
    vector<vector<int>> ans(n+1,vector<int>(m+1,0));
    
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i==0 && j==0){ ans[i][j]=1; continue; } //when both the string and pattern are empty(Its a match)
            
            if(i==0)//When string is empty but pattern is not.(no way to create pattern from empty string)
            { ans[i][j]=0; continue; }
            
            if(j==0)// when pattern is empty but string is not(one way to get empty subsequence from string)
            { ans[i][j]=1; continue; }
            
            if(A[i-1] == B[j-1]) // last chars matches
            {  ans[i][j]= ans[i-1][j-1] + ans[i-1][j];  }
            
            else // last chars does'nt matches
            {   ans[i][j]= ans[i-1][j];  }
           
        }
    }
   
    return ans[n][m];
}
