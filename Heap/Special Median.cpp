/* 
Special Median
Median finding have always been an interesting task in programming. Sometimes we need to find medians repeatedly and this task requires an optimized algorithm for finding the median. Below is one such task: You are given an array A containing N numbers. This array is called special if it satisfies one of the following properties:
There exists an element A[i] in the array such that A[i] is equal to the median of elements [A[0], A[1], ...., A[i-1]]
There exists an element A[i] in the array such that A[i] is equal to the median of elements [A[i+1], A[i+2], ...., A[N-1]]
Note:
For A[0] consider only the median of elements [A[1], A[2], ..., A[N-1]] (as there are no elements to the left of it)
For A[N-1] consider only the median of elements [A[0], A[1], ...., A[N-2]]
You need to output 1/0 (1 --> if array is special, 0 otherwise)
*/

int Solution::solve(vector<int> &A) {
    
    vector<int> vt;
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int> > min_heap;
    
    long long med=-1;
    
    for(int i=0; i<A.size(); i++)
    {
        if(max_heap.empty() || A[i]<=med){ max_heap.push(A[i]); }
        else if(A[i]>med){ min_heap.push(A[i]); }
        
        if(max_heap.size()>min_heap.size()+1){ min_heap.push(max_heap.top());  max_heap.pop(); }
        else if(min_heap.size()>max_heap.size()+1){ max_heap.push(min_heap.top());  min_heap.pop();}
        
        if(max_heap.size()>min_heap.size()){ med=max_heap.top();  }
        else if(max_heap.size()<min_heap.size()){ med=min_heap.top();   }
        else{ med=(long long )max_heap.top()+(long long )(min_heap.top()-max_heap.top() )/2;  }
        
        if(i+1<A.size() && (int)med==A[i+1]){ return 1; }
    }
    
    while(!max_heap.empty()){ max_heap.pop(); }
    while(!min_heap.empty()){ min_heap.pop(); }
    
    for(int i=A.size()-1; i>=0; i--)
    {
        if(max_heap.empty() || A[i]<=med){ max_heap.push(A[i]); }
        else if(A[i]>med){ min_heap.push(A[i]); }
        
        if(max_heap.size()>min_heap.size()+1){ min_heap.push(max_heap.top());  max_heap.pop(); }
        else if(min_heap.size()>max_heap.size()+1){ max_heap.push(min_heap.top());  min_heap.pop();}
        
        if(max_heap.size()>min_heap.size()){ med=max_heap.top();  }
        else if(max_heap.size()<min_heap.size()){ med=min_heap.top();   }
        else{ med=(long long )max_heap.top()+(long long )(min_heap.top()-max_heap.top() )/2;  }
        
        if(i-1>=0 && (int)med==A[i-1]){ return 1;  }
    }
    
    return 0;
   
}
