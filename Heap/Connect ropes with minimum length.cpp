/* 
Connect ropes with minimum length
Given an array of integers A representing the length of ropes. You need to connect these ropes into one rope.
The cost of connecting two ropes is equal to the sum of their lengths. You need to connect the ropes with 
minimum cost. Find and return the minimum cost to connect these ropes into one rope.
Return an integer corresponding to the minimum possible largest element after K operations.
 */


int Solution::solve(vector<int> &A) {
    
    priority_queue<int,vector<int>,greater<int> > heap;
    
    for(int i=0; i<A.size(); i++){ heap.push(A[i]); }
    
    int sum=0;
    while(!heap.empty())
    {
        int a=heap.top(); heap.pop();  int b=-1;
        if(!heap.empty()){ b=heap.top(); heap.pop(); }
        
        if(b!=-1){ sum+=(a+b); heap.push(a+b); }
    }
    
    return sum;
}
