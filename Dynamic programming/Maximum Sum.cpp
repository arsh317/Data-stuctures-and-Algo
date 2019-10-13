/* 

Maximum Sum
You are given an array A of N integers and three integers X, Y, and Z. You have to find the maximum value of A[i]*X + A[j]*Y + A[k]*Z, where 1 <= i <= j <= k <= N.

*/
int Solution::solve(vector<int> &A, int B, int C, int D) {
    
    /*priority_queue<int> mxh;
    //priority_queue<int,vector<int>,greater<int>> mnh;
    mxh.push(B); mxh.push(C); mxh.push(D);
    
    int mx=A[0],mn=A[0];
    for(int i=0; i<A.size(); i++)
    {
        mx=max(mx,A[i]); mn=min(mn,A[i]);
    }
    
    int sum=0;
    
    if(mxh.top()>=0){ sum+=mx*mxh.top(); mxh.pop(); }
    else{ sum+=mn*mxh.top(); mxh.pop();  }
    
    if(mxh.top()>=0){ sum+=mx*mxh.top(); mxh.pop(); }
    else{ sum+=mn*mxh.top(); mxh.pop();  }
    
    if(mxh.top()>=0){ sum+=mx*mxh.top(); mxh.pop(); }
    else{ sum+=mn*mxh.top(); mxh.pop();  }
    
    return sum;
    
    */
    
    vector<int> vt; vt.push_back(B); vt.push_back(C); vt.push_back(D);
    long long ans[A.size()][3];
    
    for(int i=0; i<A.size(); i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i==0 && j==0){ ans[i][j]=(long long)A[i]*vt[j]; continue; }
            if(i==0){ ans[i][j]=A[i]*vt[j]+ans[i][j-1]; continue; }
            if(j==0){ ans[i][j]=max((long long)A[i]*vt[j], ans[i-1][j] ); continue; }
            
            ans[i][j]=max(ans[i-1][j],A[i]*vt[j]+ans[i][j-1]);
        }
    }
    
    return ans[A.size()-1][2];
    
}
