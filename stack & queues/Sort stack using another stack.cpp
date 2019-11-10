/*
Sort stack using another stack
Given a stack of integers A, sort it using another stack. Return the array of integers after sorting the stack using another stack. 
*/

vector<int> Solution::solve(vector<int> &A) {
    
    vector<int> vt; int top=-1;
    int l=A.size();
    for(int i=0; i<l; i++){ vt.push_back(0); }
    
    for(int i=0; i<l; i++)
    {
        int ct=0; 
        while(top>=0 && A[i]<vt[top])
        { ct++; A.push_back(vt[top]); top--; }
        
        top++; vt[top]=A[i];
        while(ct>0)
        {
            top++; vt[top]=A[A.size()-1];
            A.pop_back(); ct--;
        }
    }
    
    return vt;
}
