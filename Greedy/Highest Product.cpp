/* 
 Highest Product
Given an array A, of N integers A. Return the highest product possible by multiplying 3 numbers from the array. NOTE: Solution will fit in a 32-bit signed integer. 
 Input Format: The first and the only argument is an integer array A. Output Format: Return the highest possible product. Constraints: 1 <= N <= 5e5 Example:
Input 1:
A = [1, 2, 3, 4]

Output 1:
24

Explanation 1:
2 * 3 * 4 = 24
*/

int Solution::maxp3(vector<int> &A) {
   
    priority_queue<int> mxh;
    priority_queue<int,vector<int>,greater<int>> mnh;
    
    mnh.push(A[0]); mnh.push(A[1]); mnh.push(A[2]);
    mxh.push(A[0]); mxh.push(A[1]);
    
    if(A[2]<mxh.top()){ mxh.pop(); mxh.push(A[2]); }
    
    for(int i=3; i<A.size(); i++)
    { 
        if(A[i]<mxh.top()){ mxh.pop(); mxh.push(A[i]); }
        if(A[i]>mnh.top()){ mnh.pop(); mnh.push(A[i]); }
    }
    int mx1,mx2,mx3,lw1,lw2;
    mx1=mnh.top(); mnh.pop();
    mx2=mnh.top(); mnh.pop();
    mx3=mnh.top(); mnh.pop();
    lw1=mxh.top(); mxh.pop();
    lw2=mxh.top(); mxh.pop();
    
    //cout<<mx1<<" : "<<mx2<<" : "<<mx3<<endl;
    //cout<<lw1<<" : "<<lw2<<endl;
    
    
    int mx=mx1*mx2*mx3;
    mx1=max(mx1,max(mx2,mx3));
    mx=max(mx,(mx1*lw1*lw2));
    
    if(mx==0){ mx=mx1; }
    return mx;
}
