/* 
N max pair combinations
Given two arrays A & B of size N each.
Find the maximum N elements from the sum combinations (Ai + Bj) formed from 
elements in array A and B. For example if A = [1,2], B = [3,4], then possible 
pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6 and maximum 2 elements are 6, 5 
Example: N = 4 a[]={1,4,2,3} b[]={2,5,1,6}
 */

struct node
{
    int sum;
    int i;
    int j;
    
    node(int s,int a, int b)
    { sum=s; i=a; j=b; }
};


class comp
{
    public:
    int operator()(node a, node b)
    { return (a.sum)<(b.sum); }
};



vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    
    vector<int> vt;
    
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    
    priority_queue<node,vector< node >,comp> heap;
    
    node p(A[0]+B[0],0,0);
    unordered_map<string,int> mp;
    
    string st=to_string(0)+"_"+to_string(0);
    mp[st]=1;
    heap.push(p);
    
    int ct=A.size();
    
    while(ct--)
    {
        node a=heap.top(); heap.pop();
        vt.push_back(a.sum);
        
        st=to_string(a.i+1)+"_"+to_string(a.j);
        if(a.i+1<A.size() && mp.find(st)==mp.end())
        {
            mp[st]=1;
            node nw(A[a.i+1]+B[a.j],a.i+1,a.j);
            heap.push(nw);
        }
        
        st=to_string(a.i)+"_"+to_string(a.j+1);
        if(a.j+1<B.size() && mp.find(st)==mp.end())
        {
            mp[st]=1;
            node nw(A[a.i]+B[a.j+1],a.i,a.j+1);
            heap.push(nw);
        }
    }
    
    return vt;
}
