/* 
Scooby likes the kth element
Scooby wants to help you as he knows that you are preparing for interviews. 
So Scooby gives you a very simple question. You are given N numbers. You need to 
find the kth largest element in the subarray [1 to i] where i varies from 1 to N. 
In other words you need to find the kth largest element in the sub-arrays 
[1:1], [1:2], [1:3], ...., [1:n] .
 */

vector<int> Solution::solve(int A, vector<int> &B) {
    
    vector<int> vt;
    priority_queue<int,vector<int>,greater<int> > heap;
    
    int i=0;
    for(i=0; i<A; i++){ vt.push_back(-1); heap.push(B[i]); }
    
    vt.pop_back();
    vt.push_back(heap.top());
    for(i=A; i<B.size(); i++)
    {
        if(B[i]>heap.top()){ heap.pop(); heap.push(B[i]); }
        vt.push_back(heap.top());
    }
    
    return vt;
    
}
