/*
Redundant Braces
Given a string A denoting an expression. It contains the following operators '+', '-', '*', '/'. Chech whether A has redundant braces or not. 
Return 1 if A has redundant braces, else return 0. Note: A will be always a valid expression
*/
int Solution::braces(string A) {
    
    stack<char> st;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]=='('){ st.push('('); }
        else if(A[i]==')')
        {
            if(st.empty() || st.top()=='(' ){ return 1; } 
            else if(st.top()=='.'){ st.pop(); st.pop(); }
        }
        else if(A[i]=='+' || A[i]=='-' || A[i]=='*' || A[i]=='/')
        {    if(st.empty() || st.top()=='('){ st.push('.'); }        }
    }
    
    return 0;
}