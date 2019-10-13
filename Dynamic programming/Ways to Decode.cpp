/* 

Ways to Decode
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

*/

int Solution::numDecodings(string A) {
    
    if(A[0]=='0'){ return 0; }
    
    int ans[A.size()]; memset(ans,0,sizeof(ans));
    ans[0]=1;
    
    int x=A[0]-'0';
    int y=A[1]-'0';
    
    if(y!=0){ ans[1]+=1; }
    if((x*10+y)>=10 && (x*10+y)<=26){ ans[1]+=1; }
    
    for(int i=2; i<A.size(); i++)
    {
        ans[i]=0;
        if(A[i]!='0'){ ans[i]+=ans[i-1]; }
        x=A[i-1]-'0';
        y=A[i]-'0';
        
        if((x*10+y)>=10 && (x*10+y)<=26){ ans[i]+=ans[i-2]; }
    }
    return ans[A.size()-1];
}