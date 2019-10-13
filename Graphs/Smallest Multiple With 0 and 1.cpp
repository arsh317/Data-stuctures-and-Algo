/* 

Smallest Multiple With 0 and 1
You are given an integer N. You have to find smallest multiple of N which consists of digits 0 and 1 only. Since this multiple could be large, return it in form of a string. Note:
Returned string should not contain leading zeroes.

*/



string Solution::multiple(int A) {
    
    queue<pair<string,int>> q;
    string s="1";  int rem=1%A;
    q.push({s,rem});
    
    unordered_map<int> vis;
    pair<string,int> p;
   
    
    while(!q.empty())
    {
        p=q.front(); q.pop();
        
        s=p.first;
        rem=p.second;
        
        int trem;
        
        if(rem==0){ return s; }
        
        else if(vis.find(rem)==vis.end())
        {
            vis[rem]=1;
            
            trem=rem*10+0;
            trem%=A;
            q.push( {s+"0",trem} );
            
            trem=rem*10+1;
            trem%=A;
            q.push( {s+"1",trem} );
        }
    }
    
    return "0";
    
}
