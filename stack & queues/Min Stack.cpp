/*
Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

#include <stack>
//int gtmn[1000000008],st[1000000008];
//int tp=-1;
stack<int> mn,st;

MinStack::MinStack() {
    while(!st.empty()){ st.pop(); }
    while(!mn.empty()){ mn.pop(); }
    
    //for(int i=0; i<1000000008; i++){ gtmn[i]=0; st[i]=0; }
    //tp=-1;
}

void MinStack::push(int x) {
    
    if(mn.empty() || x<mn.top()){ mn.push(x); }
    else{ mn.push(mn.top()); }
    
    st.push(x);
    
    /*if(tp<0 || x<gtmn[tp]){ tp++; gtmn[tp]=x; }
    else{ tp++; gtmn[tp]=gtmn[tp-1]; }
    st[tp]=x;*/
}
void MinStack::pop() {
    //if(tp>=0){ tp--; }
    if(!st.empty()){ st.pop(); mn.pop(); }
}

int MinStack::top() {
    if(!st.empty()){ return st.top(); }
    return -1;
    //if(tp>=0){ return st[tp]; }
    //else{ return -1; }
}

int MinStack::getMin() {
    if(!mn.empty()){ return mn.top(); }
    return -1;
    //if(tp>=0){ return gtmn[tp]; }
    //else{ return -1; }
}