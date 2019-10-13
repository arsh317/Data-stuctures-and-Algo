/* 

Flip Array
Given an array of positive elements, you have to flip the sign of some of its elements such that the resultant sum of the elements of array should be minimum non-negative(as close to zero as possible). Return the minimum no. of elements whose sign needs to be flipped such that the resultant sum is minimum non-negative.

*/

int Solution::solve(const vector<int> &A) {
    
    int sum=0;
    for(int i=0; i<A.size(); i++){ sum+=A[i]; }
    
    int n=A.size();
    pair<int,int> ans[n][sum+1];
    
    int sm=sum;
    
    for(int i=0; i<A.size(); i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(i==0)
            {
                if(j-2*A[i]<0){ ans[i][j]=make_pair(j,0); }
                else{ ans[i][j]=make_pair(j-2*A[i],1);  }
                continue;
            }
            
            int x=0,ct1=0;
            
            if(j-2*A[i]>=0) { x=ans[i-1][ j-2*A[i] ].first; ct1=1+ans[i-1][ j-2*A[i] ].second;    }
            else{ x=j; ct1=0; }
            
            int y=ans[i-1][j].first;
            int ct2=ans[i-1][j].second;
            
            if(x!=y)
            { 
                if(x<y){ ans[i][j]=make_pair(x,ct1); }
                else{ ans[i][j]=make_pair(y,ct2); }
            }
            else
            {
                if(ct1<=ct2){ ans[i][j]=make_pair(x,ct1);  }
                else{ ans[i][j]=make_pair(y,ct2);  }
            }
        }
    }
    
    return  ans[n-1][sum].second;
}
