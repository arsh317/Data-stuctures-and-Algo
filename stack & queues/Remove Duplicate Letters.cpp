/*
Remove Duplicate Letters
Given a string A consisting of lowercase English alphabets. 
Find and return lexicographically smallest string B after removing duplicate letters from 
A so that every letter appears once and only once.
*/
 
string Solution::solve(string A) {
    
    string str=""; stack<char> st;
    unordered_map<char,int> freq,instk;
    for(int i=0; i<A.size(); i++)
    {
        instk[A[i]]=0;
        if(freq.find(A[i])==freq.end()){ freq[A[i]]=1; }
        else{ freq[A[i]]++; }
    }
    
    for(int i=0; i<A.size(); i++)
    {
        if(instk[A[i]]==1){ freq[A[i]]--; continue; }
        
        while(!st.empty() && A[i]<st.top() && freq[st.top()]>0){ instk[st.top()]=0; st.pop(); }
        
        st.push(A[i]); freq[A[i]]--;
        instk[A[i]]=1;
    }
    
    while(!st.empty()){ str=str+st.top(); st.pop(); }
    
    int l=str.size();
    for(int i=0; i<=(l/2-1); i++)
    {
        char ch=str[i];
        str[i]=str[l-i-1];
        str[l-i-1]=ch;
    }
    
    return str;
}
