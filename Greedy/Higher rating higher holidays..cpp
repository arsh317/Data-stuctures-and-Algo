/* 
Higher rating higher holidays.
Scooby's summer vacations are about to start. Scooby and all his school friends are sitting 
in the class in a single line.
Every one in the class has a rating depending on their performance in InterviewBit contests. 
Number of holidays a child will get is dependent on the child's relative performance. 
The teacher is kind and wants to give atleast one holiday to each child. If two children 
are sitting next to each other then the child with higher rating should always get more holidays. 
The teacher however wants to minimize the sum of holidays give to each child. Help the teacher in distributing 
holidays to children.
*/

int Solution::solve(vector<int> &A) {
    
    if(A.empty()){ return 0; }
    
    int ans[A.size()]; memset(ans,0,sizeof(ans));
    ans[0]=1;
    
    for(int i=1; i<A.size(); i++)
    {
        if(A[i]>A[i-1]){ ans[i]=ans[i-1]+1; }
        else{ ans[i]=1; }
    }
    
    int sum=ans[A.size()-1];
    for(int i=A.size()-2; i>=0; i--)
    {
        if(A[i]>A[i+1]){ ans[i]=max(ans[i],ans[i+1]+1); }
        sum+=ans[i];
    }
    
    return sum;
    
}
