/* 
Minimum largest element after K operations
Given an array A of N numbers, you have to perform B operations. 
In each operation, you have to pick any one of the N elements and add original 
value(value stored at index before we did any operations) to it's current value. 
You can choose any of the N elements in each operation. Perform B operations in such a 
way that the largest element of the modified array(after B operations) is minimised. 
Return an integer corresponding to the minimum possible largest element after K operations.
 */


class comp
{
    public:
    int operator()(pair<int,int> a,pair<int,int> b){ return a.first>b.first; }
};

int Solution::solve(vector<int> &A, int B) {
    
    priority_queue<pair<int,int>,vector< pair<int,int> >,comp > heap;
    
    int arr[A.size()];
    for(int i=0; i<A.size(); i++)
    {  arr[i]=A[i]; heap.push( make_pair(2*A[i],i) );  }
    
    while(B--)
    {
        pair<int,int> p=heap.top(); heap.pop();
        arr[p.second]=p.first;
        
        p.first+=A[p.second];
        heap.push(p);
    }
    
    int mx=INT_MIN;
    for(int i=0; i<A.size(); i++)
    {  mx=max(mx,arr[i]);  }
    
    return mx;
}
