/* 
Longest Balanced Substring
Given a string S made up of multiple brackets of type "<>" , "[]" , "()" and "{}" find the length of the longest substring which forms a balanced string . Conditions for a string to be balanced : 1) Blank string is balanced ( However blank string will not be provided as a test case ). 2) if B is balanced : (B) , [B] , {B} and <B> are also balanced. 3) if B1 and B2 are balanced then B1B2 i.e the string formed by concatenating B1 and B2 is also balanced. Your function will get exactly one argument which would represent the string S. Your function should return an integer corresponding to the answer.
*/
char getopp(char ch)
{
    if(ch=='}'){ return '{'; }
    if(ch==']'){ return '['; }
    if(ch==')'){ return '('; }
    if(ch=='>'){ return '<'; }
}

int Solution::LBSlength(const string A) {
    
    stack<pair<char,int>> st;
    int ans[A.size()]; memset(ans,0,sizeof(ans));
    
    int mx=0;
    
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]=='(' || A[i]=='[' || A[i]=='<' || A[i]=='{')
        { st.push(make_pair(A[i],i)); ans[i]=0;  }
        else
        {
            if(!st.empty() && st.top().first==getopp(A[i]) )
            {
                int curr=i-st.top().second+1; 
                if(st.top().second>0){ curr+=ans[st.top().second-1]; }
                st.pop(); ans[i]=curr;
                mx=max(mx,curr);
            }
            else{  st.push(make_pair(A[i],i)); ans[i]=0; }
        }
    }
    
    return mx;
}
