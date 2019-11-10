/*
Maximum Frequency stack
You are given a matrix A which represent operations of size N x 2. Assume initially you have a stack-like data structure you have to perform operations on it. Operations are of two types:
1 x: push an integer x onto the stack and return -1
2 0: remove and return the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the top of the stack is removed and returned.
A[i][0] describes the type of operation to be performed. A[i][1] describe the element x or 0 corresponding to the operation performed.
*/

#include<stack>

class my_stack
{
    public:
    int mxfr=0;
    unordered_map<int,stack<int>> fr_st;
    unordered_map<int,int> freq;
    
    void pushst(int x)
    {
        if(freq.find(x)==freq.end()){ freq[x]=1; }
        else{ freq[x]++; }
        mxfr=max(mxfr,freq[x]);
        
        fr_st[freq[x]].push(x); 
    }
    
    int popst()
    {
        int t=fr_st[mxfr].top();
        freq[t]--;
        fr_st[mxfr].pop();
        if(fr_st[mxfr].empty()){ mxfr--; }
        return t;
    }
};



vector<int> Solution::solve(vector<vector<int> > &A) {
    
    my_stack stk;
    vector<int> vt;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i][0]==1){ stk.pushst(A[i][1]); vt.push_back(-1); }
        else{ vt.push_back( stk.popst() ); }
    }
    
    return vt;
    
}
