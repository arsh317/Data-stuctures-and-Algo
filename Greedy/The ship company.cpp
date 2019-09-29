/* 
The ship company
The local ship renting service has a special rate plan:
1. It is up to a passenger to choose a ship.
2. If the chosen ship has X (X > 0) vacant places at the given moment, then the ticket for such a ship costs X.
The passengers buy tickets in turn, the first person in the queue goes first, then goes the second one, 
and so on up to A-th person. You need to tell the maximum and the minimum money that the ship company 
can earn if all A passengers buy tickets.
Input format:
The first argument is a integer A  — the number of passengers in the queue 
The second arugument is a integer B  the number of ships.
The third argument is array of C integers C1,  C2,  ...,  Cm  — Ci stands for the number of empty seats in the i-th ship before the ticket office starts selling tickets.

It is guaranteed that there are at least A empty seats in total.
*/

vector<int> Solution::solve(int A, int B, vector<int> &C) {
    
    vector<int> vt;
    priority_queue<int> mxh;
    priority_queue<int,vector<int>,greater<int>> mnh;
    
    for(int i=0; i<C.size(); i++){ mxh.push(C[i]);   mnh.push(C[i]); }
    
    int mn=0,mx=0;
    while(A--)
    {
        int a=mnh.top();  mnh.pop();
        mn+=a;  a--; 
        if(a){ mnh.push(a); }
        
        a=mxh.top();  mxh.pop();
        mx+=a;  a--; 
        if(a){ mxh.push(a); }
    }
    vt.push_back(mx); vt.push_back(mn);
    
    return  vt;
}
