/* 
Transform it
You are the boss of the company having N employees. Given an array A of N integers representing representing initial salary of employees. Since you are the Boss you have to make increments in the salary of employees. You have to make increments exactly B times. In a single increment, you can select any one employee and increase its salary by its initial salary. You have to perform B increments in such a way that the largest salary among the employees(after B increments) is minimized. Return an integer corresponding to the minimum possible largest salary after B increments.
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
