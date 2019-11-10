/*
Remove Duplicate Letters
Given a string A consisting of lowercase English alphabets. Find and return lexicographically smallest string B 
after removing duplicate letters from A so that every letter appears once and only once.
*/

string rev(string &A)
{
    string s="";
    for(int i=A.size()-1; i>=0; i--){ s+=A[i];  }
    return s;
}

string Solution::solve(string A) {
    
    stack<char> st;
    unordered_map<char,int> mp,instk;
    
    for(int i=0; i<A.size(); i++){ mp[A[i]]++; }
    
    for(int i=0; i<A.size(); i++)
    {
        if(instk[A[i]]==1){  mp[A[i]]--; }
        else if(st.empty() || (int)st.top()<(int)A[i]){ st.push(A[i]); instk[A[i]]=1; mp[A[i]]--; }
        else
        {
            while(!st.empty() && (int)st.top()>(int)A[i] && mp[st.top()]>0)
            {  instk[st.top()]=0;  st.pop(); }
            st.push(A[i]);  instk[A[i]]=1; mp[A[i]]--;
        }
    }
    
    string s="";
    
    while(!st.empty()){ s+=st.top(); st.pop(); }
    
    return rev(s);
}

