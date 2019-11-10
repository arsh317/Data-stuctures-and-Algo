/*
Evaluate Expression
Evaluate the value of an arithmetic expression in Reverse Polish Notation. 
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
*/


int cal(int a,int b,string &st)
{
    if(st=="*"){ return a*b; }
    else if(st=="/"){ return a/b; }
    else if(st=="-"){ return a-b; }
    else { return a+b; }
}

int Solution::evalRPN(vector<string> &A) {
    
    stack<int> st;
    
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]!="*" && A[i]!="/" && A[i]!="+" && A[i]!="-")
        {   st.push(stoi(A[i]));  }
        
        else
        {
            int b=st.top(); st.pop();
            int a=st.top(); st.pop();
            int x=cal(a,b,A[i]);
            st.push(x);
        }
    }
    
    return st.top();
}
