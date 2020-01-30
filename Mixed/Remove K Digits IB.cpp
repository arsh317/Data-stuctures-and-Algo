Remove K Digits
Given a non-negative integer A represented as a string, remove B digits from the number so that the new number is the smallest possible. Note:
The length of A is less than 10002 and will be >= B.
The given num does not contain any leading zero.


#include <bits/stdc++.h>

string Solution::solve(string A, int B) {
    
    list<char> ans;
    int i=0;
    
    for(i=0; i<A.size(); i++)
    {
        if(B==0){ break; }
        while(!ans.empty() && ans.back()>A[i] && B>0){ B--; ans.pop_back(); }
        ans.push_back(A[i]); 
    }
    
    //cout<<i<<" "<<B<<" "<<ans<<endl;
    
    while(B>0)
    {
        ans.pop_back(); B--;
    }
    
    for(i; i<A.size(); i++){ ans.push_back(A[i]); }
    
    string real="",emp="";
    
    i=0;
    while(!ans.empty() && ans.front()=='0'){ ans.pop_front(); }
    if(ans.empty()){ ans.push_back('0'); }
    
    while(!ans.empty()){ real+=ans.front(); ans.pop_front(); }
    
    return real;
}
