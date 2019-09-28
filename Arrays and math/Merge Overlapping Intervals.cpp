/*
Given a collection of intervals, merge all overlapping intervals.
For example: Given [1,3],[2,6],[8,10],[15,18], return [1,6],[8,10],[15,18]. 
Make sure the returned intervals are sorted.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool compare(Interval a, Interval b)
{
    return a.start<b.start;
}

int max(int a,int b)
{
    if(a>=b){ return a; }
    else return b;
}


vector<Interval> Solution::merge(vector<Interval> &A) {
    
    if(A.size()<=1){ return A; }
    
    vector<Interval> vt;
    int n=A.size();
    
    sort(A.begin(),A.end(),compare);
    
    Interval pr(A[0].start,A[0].end);
    for(int i=1; i<A.size(); i++)
    {
        if(A[i].start <= pr.end)
        { pr.end=max(pr.end,A[i].end); }
        else{ vt.push_back(pr); pr=A[i]; }
    }
    
    vt.push_back(pr);
    return vt;
}
