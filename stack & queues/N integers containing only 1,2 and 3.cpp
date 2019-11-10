/*
N integers containing only 1,2 and 3
Given an integer A. Find and Return first positive A integers in ascending order containing only digits 
1,2 and 3. NOTE: all the A integers will fit in 32 bit integer.
*/

vector<int> Solution::solve(int A) {
    
    vector<int> vt;
    vt.push_back(1);  if(A==1){ return vt; }
    vt.push_back(2);  if(A==2){ return vt; }
    vt.push_back(3);  if(A==3){ return vt; }
    
    vt.pop_back(); vt.pop_back(); vt.pop_back();
    queue<int> q;
    q.push(1); q.push(2); q.push(3);
    int size=3;
    
    while(true)
    {
        int t=q.front(); q.pop(); vt.push_back(t);
        q.push((t*10+1)); size++; if(size==A){ break; }
        q.push((t*10+2)); size++; if(size==A){ break; }
        q.push((t*10+3)); size++; if(size==A){ break; }
    }
    
    while(!q.empty()){ vt.push_back(q.front()); q.pop(); }
    return vt;
    
}
