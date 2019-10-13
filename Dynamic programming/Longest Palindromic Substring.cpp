/* 

Longest Palindromic Substring
Given a string S, find the longest palindromic substring in S. Substring of string S: S[i...j] where 0 <= i <= j < len(S) Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).

*/

string Solution::longestPalindrome(string A) {
    
    if(A==""){ return A; }
    
    int n=A.size(); 
    vector<vector<bool>> ans(n,vector<bool>(n,false));
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
