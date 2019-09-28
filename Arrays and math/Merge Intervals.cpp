/**
Merge Intervals
Given a set of non-overlapping intervals, insert a new interval into the intervals 
(merge if necessary). You may assume that the intervals were initially sorted according to 
their start times. 
Example 1: Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9]




 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &A, Interval nw) {
    
    vector<Interval> vt;
    if(A.size()==0){ vt.push_back(nw); return vt;  }
    
    
    Interval st(0,0);
    int i=0,fl=0;
    while(i<A.size())
    {
        if(nw.start>=A[i].start && nw.start<=A[i].end || nw.start<A[i].start)
        {
            fl=1;
            if(nw.start<A[i].start){ st.start=nw.start; }
            else { st.start=A[i].start; }
            
            while(i<A.size() && nw.end>A[i].end)
            { i++; }
            
            if(i>=A.size()){ st.end=nw.end; vt.push_back(st); }
            else if(nw.end>=A[i].start){ st.end=A[i].end; vt.push_back(st); i++; break; }
            else{ st.end=nw.end; vt.push_back(st); break; }
        }
        else{ vt.push_back(A[i]); i++; }
    }
    
    while(i<A.size()){ vt.push_back(A[i]); i++;  }
    if(fl==0){ vt.push_back(nw); }
    
    return vt;
    
}
