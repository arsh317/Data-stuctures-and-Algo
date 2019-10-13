/* 
B Closest Points to Origin
We have a list A, of points(x,y) on the plane. Find the B closest points to the origin (0, 0). Here, the distance between two points on a plane is the Euclidean distance. You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in.)
*/


class comp
{
    public:
    int operator()(pair<int,int> a,pair<int,int> b)
    {
        long long x=abs((long long)(a.first)*(a.first))+abs((long long)(a.second)*(a.second));
        long long y=abs((long long)(b.first)*(b.first))+abs((long long)(b.second)*(b.second));
        return x<y;
    }
};

vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {
    
    vector<vector<int> > vt;
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> heap;
    
    int i=0;
    for(i=0; i<B; i++){ heap.push( make_pair(A[i][0],A[i][1])  ); }
    
    for(i=B; i<A.size(); i++)
    {
        pair<int,int> b=heap.top();
        long long x=abs((long long)(A[i][0])*(A[i][0]) ) + abs((long long)(A[i][1])*(A[i][1]) );
        long long y=abs((long long)(b.first)*(b.first))+abs((long long)(b.second)*(b.second));
        if(x<y){ heap.pop(); heap.push( make_pair(A[i][0],A[i][1]) );  }
    }
    
    while(!heap.empty())
    {
        pair<int,int> p=heap.top(); heap.pop();
        vector<int> v;  v.push_back(p.first); v.push_back(p.second);
        vt.push_back(v);
    }
    
    int l=vt.size();
    for(int i=0; i<=(l/2-1); i++)
    {
        vector<int> v=vt[i]; 
        vt[i]=vt[l-1-i]; 
        vt[l-1-i]=v;
    }
    
    return vt;
}
