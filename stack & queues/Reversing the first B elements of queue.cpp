/*
Reversing the first B elements of queue
Given an array of integers A and an integer B. we need to reverse the order of the first B 
elements of the array, leaving the other elements in the same relative order.
*/

vector<int> Solution::solve(vector<int> &A, int B) {
    
    queue<int> q; stack<int> st;
    
    for(int i=0; i<A.size(); i++){ q.push(A[i]); }
    
    int ct=B;
    while(ct--){ st.push(q.front()); q.pop(); }
    while(!st.empty()){ q.push(st.top()); st.pop(); }
    
    ct=A.size()-B;
    while(ct--){ q.push(q.front()); q.pop(); }
    
    for(int i=0; i<A.size(); i++){ A[i]=q.front(); q.pop(); }
    return A;
}
