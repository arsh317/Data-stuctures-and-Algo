/* 
Minimum Number of Refueling Stops
A car with infinite gas tank capacity initially at position 0 with B liters of gas. It uses 1 liter of gas per 1 mile that it drives. It starts moving to target position A which lies to the right of starting position. Along the way, there are gas stations. ith gas station is C[i] miles right of the starting position, and has D[i] liters of gas. What is the least number of refueling stops the car must make in order to reach its destination? If it cannot reach the destination, return -1. NOTE:
If the car reaches a gas station with 0 fuel left, the car can still refuel there.
If the car reaches the destination with 0 fuel left, it is still considered to have arrived.
 */

int Solution::solve(int A, int B, vector<int> &C, vector<int> &D) {
    
    priority_queue<int> heap;
    int maxr=B; int i=0,ct=0; 
    while(i<C.size())
    {
        while(i<C.size() && C[i]<=maxr){ heap.push(D[i]); i++; }
        if(heap.empty() && maxr<A){ return -1; }
        else if(maxr<A){ maxr+=heap.top(); heap.pop(); ct++; }
        else if(maxr>=A){ return ct; }
    }
    if(maxr>=A){ return ct; }
    while(!heap.empty())
    { 
        maxr+=heap.top(); heap.pop(); ct++;
        if(maxr>=A){ return ct; }
    }
    return -1;
    //cout<<maxr<<endl;
    //return ct;
}
