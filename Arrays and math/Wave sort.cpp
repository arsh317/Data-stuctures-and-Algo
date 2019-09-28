/*
Given an array of integers, sort the array into a wave like array and return it,
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....
*/
vector<int> Solution::wave(vector<int> &A) {
    
    sort(A.begin(),A.end());
    
    for(int i=1; i<A.size(); i+=2)
    {
        int tmp=A[i];
        A[i]=A[i-1];
        A[i-1]=tmp;
    }
    
    return A;
}
