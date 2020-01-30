class Solution {
public:
    string decodeAtIndex(string A, int k) {
        
        if(A.empty()){ return ""; }
        
        stack<pair<char,int>> st;
        string str="";
        long long ct=0;
        
        long long i=0;
        
        while(i<A.size())
        {
            
            if(A[i]>='0' && A[i]<='9')
            {
                long long no=1;
                while(i<A.size() && A[i]>='0' && A[i]<='9')
                  {
                      no= no*(A[i]-'0');
                      i++;
                  }
                long long tmp=ct*no;
                if(tmp==k){ str+=st.top().first; return str; }
                if(k<tmp){ break; }
                ct=tmp;
            }
            else
            {
                ct++;
                if(ct==k){ str+=A[i]; return str; }
                st.push({A[i],ct}); 
                i++;
            }
        }
        
        int f=k%ct;
        if(f==0){ f=ct; }
        
        while(!st.empty())
        {
            if(st.top().second==f){ str+=st.top().first; return str; }
            else if(st.top().second>f){ st.pop(); }
            else //st.top()<f
            {
                f=f%(st.top().second);
                if(f==0){ f=st.top().second; }
            }
        }
        
        return str;
        
        
        
    }
};