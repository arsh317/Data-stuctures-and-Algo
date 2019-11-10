/*
Nearest Smaller Element
Given an array, find the nearest smaller element G[i] for
every element A[i] in the array such that the element has an index smaller than i.
*/

vector<int> Solution::prevSmaller(vector<int> &A) {
    
    stack<int> st;
    vector<int> ple;
    
    for(int i=A.size()-1; i>=0; i--){ ple.push_back(-1); }
    
    for(int i=A.size()-1; i>=0; i--)
    {
        if(st.empty()){ st.push(i); }
        else if(!st.empty() && A[i]>=A[st.top()]){ st.push(i); }
        else
        {
            while(!st.empty() && A[i]<A[st.top()])
            { ple[st.top()]=A[i]; st.pop(); }
            st.push(i);
        }
    }
    
    while(!st.empty())
    {
        ple[st.top()]=-1;
        st.pop();
    }
    
    return ple;
}
