/* 
Median of stream of running integers
Given an array of integers A denoting a stream of integers. A new array of integer B is formed and C are formed. Each time an integer is encountered in a stream append it at the end of B and append median of array B at the C. Find and return the array C. NOTE: 1.If the number of elements are n in B and n is odd then consider medain as B[n/2] ( B must be in sorted order). 2.If the number of elements are n in B and n is even then consider medain as B[n/2-1] ( B must be in sorted order)
 */

vector<int> Solution::solve(vector<int> &A) {
    
    vector<int> vt;
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int> > min_heap;
    
    int med=-1;
    
    for(int i=0; i<A.size(); i++)
    {
        if(max_heap.empty() || A[i]<=med){ max_heap.push(A[i]); }
        else if(A[i]>med){ min_heap.push(A[i]); }
        
        if(max_heap.size()>min_heap.size()+1){ min_heap.push(max_heap.top());  max_heap.pop(); }
        else if(min_heap.size()>max_heap.size()+1){ max_heap.push(min_heap.top());  min_heap.pop();}
        
        if(max_heap.size()>min_heap.size()){ med=max_heap.top(); vt.push_back(med);  }
        else if(max_heap.size()<min_heap.size()){ med=min_heap.top(); vt.push_back(med);  }
        else{ med=max_heap.top(); vt.push_back(med);  }
    }
    
    return vt;
}
  