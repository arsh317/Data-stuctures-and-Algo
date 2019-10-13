/* 

Intersecting Chords in a Circle
Given a number A, return number of ways you can draw A chords in a circle with 2 x A points such that no 2 chords intersect. Two ways are different if there exists a chord which is present in one way and not in other. Return the answer modulo 109 + 7. 
 
*/

int Solution::chordCnt(int A) {
    
    vector<long long> ans(A+1,0);
    ans[0]=ans[1]=1;
    
    int p=1000000007;
    
    for(int i=2; i<=A; i++)
    {
        for(int j=0; j<i; j++)
        {
            long long temp=(long long)ans[j]%p*ans[i-j-1]%p;
            temp%=p;
            ans[i]+=temp; ans[i]%=p;
        }
    }
    
    return (int)ans[A];
}

