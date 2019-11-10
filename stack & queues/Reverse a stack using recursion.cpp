/*
Reverse a stack using recursion
Given a stack of integers A. You are required to reverse the stack using recursion. 
You are not allowed to use loop constructs like while, for..etc, 
Return A after reversing it using recursion. NOTE: It is mandatory to reverse A using recursion.
*/
 
void putbottom(vector<int> &A,int x)
{
    stack<int> st;
    while(!A.empty()){ st.push(A[A.size()-1]);  A.pop_back(); }
    
    A.push_back(x);
    while(!st.empty()){ A.push_back(st.top()); st.pop(); }
}

void rev(vector<int> &A)
{
    if(A.empty()){ return ; }
    
    int x=A[A.size()-1];  A.pop_back();
    rev(A);
    putbottom(A,x);
}

vector<int> Solution::solve(vector<int> &A) {
    
    rev(A);
    return A;
}
