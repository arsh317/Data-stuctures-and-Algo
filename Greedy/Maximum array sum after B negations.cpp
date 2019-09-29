/* 
Maximum array sum after B negations
Given an array of integers A and an integer B. You must modify the array exactly B number of times.
In single modification we can replace any one array element A[i] by -A[i]. You need to perform these modifications 
in such a way that after exactly B modifications, sum of the array must be maximum. 
*/


class comp
{
    public:
    int operator()(pair<int,int> a,pair<int,int>b)
    { return a.first>b.first; }
};


int Solution::solve(vector<int> &A, int B) {
    
    priority_queue<pair<int,int>,vector<pair<int,int> >,comp > heap;
    
    for(int i=0; i<A.size(); i++)
    {
        heap.push(make_pair(A[i],i));
    }
    
    while(B)
    {
        pair<int,int> t=heap.top(); 
        if(t.first<0){ t.first=-t.first; A[t.second]=0-A[t.second]; heap.pop(); heap.push(t); }
        else
        {
            if(B%2==1){ A[t.second]=0-A[t.second]; }
            break;
        }
        B--;
    }
    
    int sum=0;
    for(int i=0; i<A.size(); i++)
    {
        sum+=A[i];
    }
    
    
    return sum;
}
